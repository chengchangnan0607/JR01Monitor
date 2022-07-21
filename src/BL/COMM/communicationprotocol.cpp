#include "communicationprotocol.h"
#include <string.h>
#include <stdlib.h>
#include <qstring.h>
#include <qdebug.h>
#include <iostream>


CommunicationProtocol::CommunicationProtocol()
{

}

CommunicationProtocol::~CommunicationProtocol()
{

}

bool CommunicationProtocol::Unpack(unsigned char *data, int &len, unsigned char *des, int des_len) {
    if (len < PR_PACKET_LEN) {                               //长度不够
        return false;
    }
    int head_pos = -1;
    for (int i = 0; i < len; i++) {                          //找到第一个头
        if (*(data + i) == PR_HEAD) {
            head_pos = i;
            break;
        }
    }
    if (head_pos == -1) {                                     //没有找到头，数据全部丢弃
        len = 0;
        return false;
    }
    if (len < head_pos + PR_PACKET_LEN) {                     //丢弃帧头之前无效数据后长度不够
        MoveData(data, len, head_pos);                        //移动数据
        len = len - head_pos;
        return false;
    }
    if (*(data + head_pos + PR_PACKET_LEN - 1) != PR_END) {   //判断帧尾
        MoveData(data, len, head_pos + 1);
        len = len - head_pos - 1;
        return false;
    }
    if (des == nullptr) {                                     // 获得了一包数据
        memcpy(mPRPacket, data + head_pos, PR_PACKET_LEN);
        MoveData(data, len, head_pos + PR_PACKET_LEN);
        len = len - head_pos - PR_PACKET_LEN;
    } else {
        memcpy(des, data + head_pos, des_len);
        MoveData(data, len, head_pos + des_len);
        len = len - head_pos - des_len;
    }
    return true;
}

void CommunicationProtocol::MoveData(unsigned char *data, int data_size, int begin) {
    if (begin <= 0) {
        return;
    }
    if (begin >= data_size) {
        return;
    }
    for (int i = 0; i < data_size - begin; i++) {
        *(data + i) = *(data + begin + i);
    }
}

uint16_t CommunicationProtocol::Crc16(uint16_t initCrc16, uint8_t *pDataBuf, uint16_t byteCount)
{
   uint16_t i;
   uint16_t resultCrc = initCrc16;
   for (i = 0; i < byteCount; i++) {
      resultCrc = g_crc16Map[(int) (resultCrc ^ pDataBuf[i]) & 0xff] ^ (((resultCrc) >> 8) & 0x00FF);
   }
   return resultCrc;
}

#define CL0   (20333.1)
#define p0   (-0.02267852)
#define p1    (0.7545588)
#define p2   (-0.0007141285)
#define p3    (0.000007044587)
#define p4   (-0.00000002077896)
#define p5    (0.00000000002114092)

float CommunicationProtocol::calculatePressure(S200RealtimeData sensorData)
{
    float cavityLength = (sensorData.S200CavityLength[0] << 8) + sensorData.S200CavityLength[1] + (sensorData.S200CavityLength[2]/256.0);
    float tCL = CL0 - cavityLength;
    float pressuremmHg = (p5*tCL*tCL*tCL*tCL*tCL) + (p4*tCL*tCL*tCL*tCL) + (p3*tCL*tCL*tCL) + (p2*tCL*tCL) + (p1*tCL) + p0;
    if (pressuremmHg > 10000) {
        pressuremmHg = 0;
    }
    return pressuremmHg;
}


