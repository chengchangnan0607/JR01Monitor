#ifndef COMMUNICATIONPROTOCOL_H
#define COMMUNICATIONPROTOCOL_H

#include "QString"

#define PR_PACKET_LEN 16

#define CRC16_INIT_VALUE    (0xAAAA)
#define CRC16_TABLE                                                   \
   {                                                                  \
    0x0000, 0x1189, 0x2312, 0x329b, 0x4624, 0x57ad, 0x6536, 0x74bf,   \
    0x8c48, 0x9dc1, 0xaf5a, 0xbed3, 0xca6c, 0xdbe5, 0xe97e, 0xf8f7,   \
    0x1081, 0x0108, 0x3393, 0x221a, 0x56a5, 0x472c, 0x75b7, 0x643e,   \
    0x9cc9, 0x8d40, 0xbfdb, 0xae52, 0xdaed, 0xcb64, 0xf9ff, 0xe876,   \
    0x2102, 0x308b, 0x0210, 0x1399, 0x6726, 0x76af, 0x4434, 0x55bd,   \
    0xad4a, 0xbcc3, 0x8e58, 0x9fd1, 0xeb6e, 0xfae7, 0xc87c, 0xd9f5,   \
    0x3183, 0x200a, 0x1291, 0x0318, 0x77a7, 0x662e, 0x54b5, 0x453c,   \
    0xbdcb, 0xac42, 0x9ed9, 0x8f50, 0xfbef, 0xea66, 0xd8fd, 0xc974,   \
                                                                      \
    0x4204, 0x538d, 0x6116, 0x709f, 0x0420, 0x15a9, 0x2732, 0x36bb,   \
    0xce4c, 0xdfc5, 0xed5e, 0xfcd7, 0x8868, 0x99e1, 0xab7a, 0xbaf3,   \
    0x5285, 0x430c, 0x7197, 0x601e, 0x14a1, 0x0528, 0x37b3, 0x263a,   \
    0xdecd, 0xcf44, 0xfddf, 0xec56, 0x98e9, 0x8960, 0xbbfb, 0xaa72,   \
    0x6306, 0x728f, 0x4014, 0x519d, 0x2522, 0x34ab, 0x0630, 0x17b9,   \
    0xef4e, 0xfec7, 0xcc5c, 0xddd5, 0xa96a, 0xb8e3, 0x8a78, 0x9bf1,   \
    0x7387, 0x620e, 0x5095, 0x411c, 0x35a3, 0x242a, 0x16b1, 0x0738,   \
    0xffcf, 0xee46, 0xdcdd, 0xcd54, 0xb9eb, 0xa862, 0x9af9, 0x8b70,   \
                                                                      \
    0x8408, 0x9581, 0xa71a, 0xb693, 0xc22c, 0xd3a5, 0xe13e, 0xf0b7,   \
    0x0840, 0x19c9, 0x2b52, 0x3adb, 0x4e64, 0x5fed, 0x6d76, 0x7cff,   \
    0x9489, 0x8500, 0xb79b, 0xa612, 0xd2ad, 0xc324, 0xf1bf, 0xe036,   \
    0x18c1, 0x0948, 0x3bd3, 0x2a5a, 0x5ee5, 0x4f6c, 0x7df7, 0x6c7e,   \
    0xa50a, 0xb483, 0x8618, 0x9791, 0xe32e, 0xf2a7, 0xc03c, 0xd1b5,   \
    0x2942, 0x38cb, 0x0a50, 0x1bd9, 0x6f66, 0x7eef, 0x4c74, 0x5dfd,   \
    0xb58b, 0xa402, 0x9699, 0x8710, 0xf3af, 0xe226, 0xd0bd, 0xc134,   \
    0x39c3, 0x284a, 0x1ad1, 0x0b58, 0x7fe7, 0x6e6e, 0x5cf5, 0x4d7c,   \
                                                                      \
    0xc60c, 0xd785, 0xe51e, 0xf497, 0x8028, 0x91a1, 0xa33a, 0xb2b3,   \
    0x4a44, 0x5bcd, 0x6956, 0x78df, 0x0c60, 0x1de9, 0x2f72, 0x3efb,   \
    0xd68d, 0xc704, 0xf59f, 0xe416, 0x90a9, 0x8120, 0xb3bb, 0xa232,   \
    0x5ac5, 0x4b4c, 0x79d7, 0x685e, 0x1ce1, 0x0d68, 0x3ff3, 0x2e7a,   \
    0xe70e, 0xf687, 0xc41c, 0xd595, 0xa12a, 0xb0a3, 0x8238, 0x93b1,   \
    0x6b46, 0x7acf, 0x4854, 0x59dd, 0x2d62, 0x3ceb, 0x0e70, 0x1ff9,   \
    0xf78f, 0xe606, 0xd49d, 0xc514, 0xb1ab, 0xa022, 0x92b9, 0x8330,   \
    0x7bc7, 0x6a4e, 0x58d5, 0x495c, 0x3de3, 0x2c6a, 0x1ef1, 0x0f78    \
}

const uint16_t g_crc16Map[256] = CRC16_TABLE;

const unsigned char  PR_REQ          = 0x00;  // type 请求
const unsigned char  PR_RSP          = 0x80;  // type 返回
const unsigned char  PR_HEAD         = 0xD0;  // 头
const unsigned short PR_HID          = 0x00;  // 硬件通道标识符
const unsigned char  PR_END          = 0x0D;  // 尾
const unsigned char  PR_PCOUNT_MASK  = 0x7f;  // 多包计数器
const unsigned char  PR_TYPE_MASK    = 0x80;  // bit7传输类型XFERTYPE, 0 = xferNormal; 1 = xferAbort

enum PR_Packet {
    SOf = 0,
    HardID1,
    HardID2,
    TypePackCounter,
    TransactionID,
    Data0,
    Data1,
    Data2,
    Data3,
    Data4,
    Data5,
    Data6,
    Data7,
    CRC16L,
    CRC16H,
    EOf
};

struct T_Acl {
    unsigned int timeStamp;
    unsigned short activityId;
    unsigned short priority;
    unsigned int errRecId;
    unsigned int parameter1;
    unsigned int parameter2;
    unsigned short conMsgId;
    unsigned short crc16;
};

struct T_AclIndex {
    unsigned int timeStamp;
    unsigned short activityId;
};

struct T_ActiveFault {
    unsigned short causeID;
    unsigned short faultcode;
    unsigned int errRecId;
    unsigned int setTime;
    unsigned int clearTime;
    unsigned int p1;
    unsigned int p2;
    unsigned int setCounter;
    unsigned short conMsgId;
    unsigned short crc16;
};

struct T_ActivityLog {
    unsigned int handle;
    T_Acl        aclData;
    unsigned short pad;
    unsigned short crc16;
};

struct T_BoardExeAccess {
    unsigned int rw;
    unsigned int mode;
    unsigned int id_address;
    unsigned int data;
};

struct T_SWV {
    unsigned short Rev;
    unsigned char Minor;
    unsigned char Major;
};

struct T_ControllerInfo {
    struct T_SWV primaryVersion;
    struct T_SWV PumpVersion;
    unsigned int primaryAppId;
    unsigned int monitorAppId;
    unsigned char controllerSN[14];
    unsigned short crc16;
};

struct T_AlarmAndPumpStatus {         //Offset
    unsigned short muteStatus:1;      //0
    unsigned short activeAlarm:3;     //1
    unsigned short pump_connmode:2;   //4
    unsigned short pump_command:1;     //6
    unsigned short pump_pmcmode:1;    //7
    unsigned short pump_state:3;      //8
    unsigned short intbatt_conn:1;    //11
    unsigned short controller_mode:4; //12
 //   unsigned short reserved:3;        //13
};

struct PowerState
{
    unsigned char wpowerType;
    unsigned char wpowerRc;
    unsigned char bpowerType;
    unsigned char bpowerRc;
};

struct T_ControllerStatus {
    unsigned int timeStamp;
    unsigned int activeFaults;
    unsigned short average1SecSpeed;
    unsigned short average1SecPower;
    unsigned short average1SecFlow;
    struct T_AlarmAndPumpStatus activeAlarmAndPumpStatus;
    unsigned short maxpower_pm;
    unsigned short minpower_pm;
    unsigned short maxflow_pm;
    unsigned short minflow_pm;
    unsigned short flow_pi;
    unsigned short heartbeat;
    unsigned short iqCurrent;
    struct PowerState powerState;
    unsigned short crc16;
};

struct T_CtrlSWV {
    struct T_SWV primaryVersion;
    struct T_SWV backupVersion;
};

struct T_ERRIndex {
    unsigned int errRecId;
    unsigned short errorRecItemIndex;
    unsigned short padding;
};

struct T_ErrItem {
    unsigned int errId;
    unsigned short ItemId;
    unsigned short pad;
    unsigned short errData[100];
    unsigned short pad2;
    unsigned short crc16;
};

struct T_ErrBusVoltagePlot {
    unsigned short data[100];
};

struct T_ErrDrivelineWire2CurrentPlot {
    unsigned short data[100];
};

struct T_ErrFlowPlot {
    unsigned short data[100];
};

struct T_ErrPhaseCurrentPlot {
    unsigned short data[100];
};

struct T_ErrPowerPlot {
    unsigned short data[100];
};

struct T_ErrSpeedPlot {
    unsigned short data[100];
};

struct T_ErrSummary {
    unsigned int timeStamp;
    struct T_AlarmAndPumpStatus activeAlarmAndPumpStatus;
    unsigned short pad;
    unsigned short pulsatilityIndex;
    unsigned short pulseRate;
    unsigned short monitorSpeed[30];
    unsigned short monitorPhaseCurrent[30];
    unsigned short average30SecVoltage3;
    unsigned short min30SecVoltage3_3;
    unsigned short max30SecVoltage3_3;
    unsigned short average30SecBlackVoltage;
    unsigned short min30SecBlackVoltage;
    unsigned short max30SecBlackVoltage;
    unsigned short average30SecWhiteVoltage;
    unsigned short min30SecWhiteVoltage;
    unsigned short max30SecWhiteVoltage;
    unsigned short average30SecInternalBatteryVoltage;
    unsigned short min30SecInternalBatteryVoltage;
    unsigned short max30SecInternalBatteryVoltage;
    unsigned short primaryTemp;
    unsigned short monitorTemp;
};

struct T_FifoRequest {
    unsigned short logRequest;
    unsigned short numberRequested;
    unsigned int handle;
};

struct T_FifoRequestResponse {
    unsigned short logRequest;
    unsigned short numberAvailable;
};

struct T_FlashData {
    unsigned int addressInByptes;
    unsigned int sectionID;
    unsigned char data[256];
    unsigned int dataLengthInBytes;
    unsigned short pad;
    unsigned short crc16;
};

struct T_Lgt {
    unsigned int timeStamp;
    struct T_AlarmAndPumpStatus pumpAndAlarmStatus;
    unsigned short average1HourFlow;
    unsigned short min1HourFlow;
    unsigned short max1HourFlow;
    unsigned short average1HourSpeed;
    unsigned short min1HourSpeed;
    unsigned short max1HourSpeed;
    unsigned short average1HourPower;
    unsigned short min1HourPower;
    unsigned short max1HourPower;
    unsigned short average1HourPulsatilityIndex;
    unsigned short min1HourPulsatilityIndex;
    unsigned short max1HourPulsatilityIndex;
    unsigned short average1HourPulseRate;
    unsigned short min1HourPulseRate;
    unsigned short max1HourPulseRate;
    unsigned short average1HourPumpPhaseCurrent[3];
    unsigned short average1HourDrivelineWire2Current[3];
    unsigned short min1HourTemp;
    unsigned short max1HourTemp;
    unsigned short pad;
    unsigned short crc16;
};

struct T_LgtItem {
    unsigned int handle;
    struct T_Lgt lgtData;
    unsigned short pad;
    unsigned short crc16;
};

struct T_PacketStruct {
    unsigned short hwChannelId;
    unsigned short packetHeader;
    unsigned short packetData[8];
};

struct T_PatientConfig {
    unsigned short Name[8];
    unsigned char gender;
    unsigned char weight;
    unsigned char height;
    unsigned char hospitalNum;
    unsigned short birthDate;
    unsigned short implantDate;
    unsigned short REV[3];
    unsigned short crc16;
};

struct T_PumpConfig {
    unsigned short min_pi;
    unsigned short lowflowlim;
    unsigned short min_peakflow;
    unsigned short crc16;
};

struct T_PumpControl {
    unsigned short Flags;//1 =启动泵; 0 =停止泵
};

struct T_PumpSpeed {
    unsigned short patientSpeedSetpoint;
    unsigned short patientMinSpeed;
    unsigned short patientMaxSpeed;
    unsigned short powerThreshold;
};

struct T_FLOWEST_HCTADJ {
    unsigned short hct;
    unsigned short comp;
    unsigned short rev;
    unsigned short crc16;
};

struct T_PMC_CONFIG {
    unsigned short id_high;
    short id_low;
    unsigned short zero_duration;
    unsigned short hold_duration;
};

struct T_PUMP_ID {
    unsigned char productid;
    unsigned char partid;
    unsigned char year;
    unsigned char no_low8;
    unsigned char no_high8;
    unsigned char rev;
    unsigned short crc16;
};

struct T_ExtPowerInfo {
    unsigned char type;
    unsigned char rc;
    unsigned short temperature;
    unsigned short cyclecount;
    unsigned short voltage;
    unsigned short current;
    unsigned short status;
};

struct T_PowerStatus {
    unsigned short status;
    struct T_ExtPowerInfo wpower;
    struct T_ExtPowerInfo bpower;
    unsigned short crc16;
};

struct T_ExtBatteryInfo_1 {
    unsigned short fault;
    unsigned short relativecapacity;
    unsigned short temperature;
    unsigned short cyclecount;
};

struct T_ExtBatteryInfo_2 {
    unsigned short voltage;
    unsigned short current;
    unsigned short batstate;
    unsigned short crc16;
};

struct T_ReadRequest {
    unsigned int addressInBytes;
    unsigned int sectionID;
    unsigned int dataLengthInBytes;
    unsigned short pad;
    unsigned short crc16;
};

struct T_RTC {
    unsigned int dateTime;
};

struct S200RealtimeData {
    unsigned char S200Version;
    unsigned char S200CavityLength[3];
    unsigned char S200Pressure[3];
};

struct PurgeRealtimeData {
    unsigned short pressure;
    unsigned short flowRate;
    unsigned short selfTest;
    unsigned char  motorFault;//bit[5:0]=motor fault;bit[7:6]=over pressure
    unsigned char  status;
};

struct T_RTS {
    unsigned short speed;
    unsigned short power;
    unsigned short flow;
    unsigned char  powerStatus;     //bit[2:0]:powerStatus;bit3:0=power on,1=power off;bit[7:4]=UART5(sensor)\4(purge)\3(motor)\2(bluetooth) connect status:1=connect,0=disconnect
    unsigned char  relativeCapacity;//bit[6:0]:relativeCapacity
    unsigned char  keyStatus;       //bit[7:0]:Alarm\Motor\Purge\Infor\Set\CHZ\CH_Add\CH_Sub
    struct S200RealtimeData sensorData;//7 Byte
    struct PurgeRealtimeData purgeDate;//8 Byte
    unsigned short crc16;
};

struct T_SHA1Hash {
    unsigned int hash[5];
    unsigned short hashVersion;
    unsigned short crc16;
};

struct T_Stt {
    unsigned int timeStamp;
    struct T_AlarmAndPumpStatus pumpAndAlarmStatus;
    unsigned short average10SecFlow;
    unsigned short min10SecFlow;
    unsigned short max10SecFlow;
    unsigned short average10SecSpeed;
    unsigned short min10SecSpeed;
    unsigned short max10SecSpeed;
    unsigned short average10SecPower;
    unsigned short min10SecPower;
    unsigned short max10SecPower;
    unsigned short pad;
    unsigned short crc16;
};

struct T_SttItem {
    unsigned int handle;
    struct T_Stt sttData;
    unsigned short pad;
    unsigned short crc16;
};

struct T_PktHeaderField {           //Offset
    unsigned short multiPktIndex:7; //0
    unsigned short xferType:1;      //7
    unsigned short transactionID:8; //8
};

enum E_XferType {
    XFERTYPE_NORMAL = 0,
    XFERTYPE_ABORT,
    XFERTYPE_COUNT
};

enum E_ActiveAlarm {
    ACTIVE_ALARM_NO_ALARM                 = 0,
    ACTIVE_ALARM_YELLOW_LOW_SYSSTATUS     = 1,
    ACTIVE_ALARM_YELLOW_SYSSTATUS         = 2,
    ACTIVE_ALARM_RED_SYSSTATUS            = 3,
    ACTIVE_ALARM_YELLOW_LOW_WHITE_POWCONN = 4,
    ACTIVE_ALARM_YELLOW_WHITE_POWCONN     = 5,
    ACTIVE_ALARM_RED_WHITE_POWCONN        = 6,
    ACTIVE_ALARM_YELLOW_LOW_BLACK_POWCONN = 7,
    ACTIVE_ALARM_YELLOW_BLACK_POWCONN     = 8,
    ACTIVE_ALARM_RED_BLACK_POWCONN        = 9
};

enum E_ActiveFaults {
    FCAUSE_DRIVELINE_DISCONNECTED           	 = 0,  //泵血电机通信异常
    FCAUSE_PUMP_ID_FAULT                         = 1,  //泵ID异常
    FCAUSE_VADCTRL_RED_FAULT                	 = 2,  //泵血电机异常
    FCAUSE_PUMP_POSITION_FAULT                   = 3,  //泵位置异常

    FCAUSE_INFUSION_BAG_LOW                      = 4,  //输液袋余量低
    FCAUSE_INFUSION_BAG_TOO_LOW                  = 5,  //输液袋余量过
    FCAUSE_PURGE_SYSTEM_BUBBLE                   = 6,  //冲洗系统气泡
    FCAUSE_PURGE_SYSTEM_BLOCK                    = 7,  //冲洗系统阻塞
    FCAUSE_PURGE_SYSTEM_LEAK                     = 8,  //冲洗系统漏液
    FCAUSE_PURGE_SYSTEM_DOOR_OPEN                = 9,  //冲洗系统泵门打开
    FCAUSE_PURGE_SYSTEM_FAULT                    = 10,  //冲洗系统硬件故障

    FCAUSE_PIPE_REPLACE_PERIOD                   = 11,
    FCAUSE_PIPE_REPLACE_TIMEOUT                  = 12,  //管路更换超时

    FCAUSE_CONSOLE_OVER_TEMP                     = 13,  //控制台温度过高

    FCAUSE_BATTERY_FAULT                         = 14,  //电池
    FCAUSE_BATTERY_LOW                           = 15,  //电池电量低
    FCAUSE_BATTERY_TOO_LOW                       = 16,  //电池电量过低

    FCAUSE_STORAGE_SPACE_NOT_ENOUGH              = 17,
    FCAUSE_OPTICAL_FIBER_FAULT                   = 18,  //光纤压力传感器故障

    FCAUSE_MAX,
}; // Fault Cause ID 报警日志 ID


enum T_ActivityLogID {
    ACT_LOG_CONTROLLER_MODE_CHANGE = 2048,
    ACT_LOG_COMM_DISCONNECT,
    ACT_LOG_COMM_AUTH_SUCCESS,
    ACT_LOG_COMM_AUTH_FAILURE,
    ACT_LOG_PUMP_CONTROL,           //5
    ACT_LOG_PUMP_SPEED,
    ACT_LOG_EBB_CHARGING,
    ACT_LOG_EBB_CHARGED,
    ACT_LOG_EBB_USING,
    ACT_LOG_MUTE,                   //10
    ACT_LOG_RED_SOUND_ON,
    ACT_LOG_YLR_SOUND_ON,
    ACT_LOG_LYLR_SOUND_ON,
    ACT_LOG_SOUND_OFF,
    ACT_LOG_SET_RTC,                //15
    ACT_LOG_RESET_CAUSE,
    ACT_LOG_EXCEPTION,
    ACT_LOG_WATCHDOG,
    ACT_LOG_SHUTDOWN_START,
    ACT_LOG_SHUTDOWN_ABORT,         //20
    ACT_LOG_PUMP_THRESHOLD,
    ACT_LOG_PUMP_SETPMC,
    ACT_LOG_PUMP_CONTROLPMC,
    ACT_LOG_PUMP_SETHTC,
    ACT_LOG_PUMP_LIN,               //25
    ACT_LOG_BATTERY_ERROR,
    ACT_LOG_BATTERYPACK_ERROR,
    ACT_LOG_PATIENT_NAME,
    ACT_LOG_HOSPITAL_INFO,
    ACT_LOG_BLACK_VOLTFLICKER,      //30
    ACT_LOG_WHITE_VOLTFLICKER,
    ACT_LOG_MOTOR_VOLTFLICKER,      //2079
    ACT_LOG_MOTOR_CONNFLICKER,      //2080
    ACT_LOG_ADC_REINIT,             //2081
    ACT_LOG_MAX
};//事件日志 ID

const QString events[ACT_LOG_MAX] = {
    "控制器模式更改",             //0
    "通信断开",                  //1
    "通信验证成功",              //2
    "通信验证失败",              //3
    "泵控制",                   //4
    "泵速",                    //5
    "应急备用电池正在充电",       //6
    "应急备用电池充电完成",       //7
    "应急备用电池正在使用",       //8
    "静音",                    //9
    "高优级音频报警",           //10
    "中优级音频报警",           //11
    "低优级音频报警",           //12
    "声音报警关",              //13
    "设置实时时钟",            //14
    "异常",                   //15
    "看门狗",                 //16
    "关机开始",                   //17
    "关机中止",               //18
    "泵阈值",                 //19
    "设置泵PMC",               //20
    "控制泵PMC",              //21
    "设置泵HTC",              //22
    "泵LIN通信联接",           //23
    "电池错误",              //24
    "备用电池错误",           //25
    "病人姓名",                      //26
    "医院信息",              //27
    "黑色电源电压闪烁",       //28
    "白色电源电压闪烁",       //29
    "泵电机电源电压闪烁",     //30
    "泵电机连接闪烁",        //31
    "ADC重新初始化"         //32
};

enum faultItem {
    faultItemPriority = 0,
    faultItemInformation = 1,
    faultItemHandling = 2
};

enum AlarmStatusPriority {
    priorityHigh = 0,
    priorityMiddle = 1,
    priorityLow = 2
};

const QString faults[FCAUSE_MAX][3] = {
    {"高", "泵电机通信异常",              "请尽快联系厂家"}, //0
    {"高", "泵连接异常",                 "请连接泵"},      //1
    {"高", "泵电机异常",                 "请尽快联系厂家"},//2
    {"高", "泵位置异常",                 "请尽快联系厂家"},//3
    {"低", "输液袋余量低",               "请更换输液袋"},//4
    {"中", "输液袋余量过低",              "请更换输液袋"},//5
    {"高", "输液管路中有气泡",            "请尽快联系厂家"},//6
    {"高", "输液管路阻塞",                "请更换输液管路"},//7
    {"高", "输液管路漏液",                "请更换输液管路"},//8
    {"高", "冲洗系统泵门打开",             "请关闭泵门"},//9
    {"中", "冲洗系统故障",                "请尽快联系厂家"},//10
    {"中", "冲洗管路更换周期",             "请尽快更换输液管路"},//11
    {"中", "冲洗管路更换超时",             "请尽快更换输液管路"},//12
    {"中", "控制台温度过高",               "请尽快联系厂家"},  //13
    {"中", "电池异常",                    "请尽快联系厂家"}, //14
    {"中", "电池电量低",                  "请尽快连接电源充电"}, //15
    {"中", "电池电量过低",                 "请尽快连接电源充电"}, //16
    {"低", "存储空间不足",                 "请尽快联系厂家"}, //17
    {"中", "传感器故障",                   "请尽快联系厂家"} //18
};

enum E_AbortCause {
    APP_REJECTION = 0,
    XFER_OUT_OF_SEQUENCE,
    CRC_MISMATCH,
    PACKET_OUT_OF_SEQUENCE,
    TRANSACTION_UNSUPPORT,
    TRANSACTION_BUSY,
    TIMEOUT_REPLY,
    TIMEOUT_MULTIPACKET,
    TIMEOUT_TX
};

enum T_ErrIndexName {
    ERR_INDEX_SUMMARY = 0,
    ERR_INDEX_FLOW1,
    ERR_INDEX_FLOW2,
    ERR_INDEX_FLOW3,
    ERR_INDEX_FLOW4,
    ERR_INDEX_FLOW5,
    ERR_INDEX_FLOW6,
    ERR_INDEX_SPEED1,
    ERR_INDEX_SPEED2,
    ERR_INDEX_SPEED3,
    ERR_INDEX_SPEED4,
    ERR_INDEX_SPEED5,
    ERR_INDEX_SPEED6,
    ERR_INDEX_POWER1,
    ERR_INDEX_POWER2,
    ERR_INDEX_POWER3,
    ERR_INDEX_POWER4,
    ERR_INDEX_POWER5,
    ERR_INDEX_POWER6,
    ERR_INDEX_PHASE_A_CURRENT1,
    ERR_INDEX_PHASE_A_CURRENT2,
    ERR_INDEX_PHASE_A_CURRENT3,
    ERR_INDEX_PHASE_A_CURRENT4,
    ERR_INDEX_PHASE_A_CURRENT5,
    ERR_INDEX_PHASE_A_CURRENT6,
    ERR_INDEX_PHASE_B_CURRENT1,
    ERR_INDEX_PHASE_B_CURRENT2,
    ERR_INDEX_PHASE_B_CURRENT3,
    ERR_INDEX_PHASE_B_CURRENT4,
    ERR_INDEX_PHASE_B_CURRENT5,
    ERR_INDEX_PHASE_B_CURRENT6,
    ERR_INDEX_PHASE_C_CURRENT1,
    ERR_INDEX_PHASE_C_CURRENT2,
    ERR_INDEX_PHASE_C_CURRENT3,
    ERR_INDEX_PHASE_C_CURRENT4,
    ERR_INDEX_PHASE_C_CURRENT5,
    ERR_INDEX_PHASE_C_CURRENT6,
    ERR_INDEX_WIRE2_A_CURRENT1,
    ERR_INDEX_WIRE2_A_CURRENT2,
    ERR_INDEX_WIRE2_A_CURRENT3,
    ERR_INDEX_WIRE2_A_CURRENT4,
    ERR_INDEX_WIRE2_A_CURRENT5,
    ERR_INDEX_WIRE2_A_CURRENT6,
    ERR_INDEX_WIRE2_B_CURRENT1,
    ERR_INDEX_WIRE2_B_CURRENT2,
    ERR_INDEX_WIRE2_B_CURRENT3,
    ERR_INDEX_WIRE2_B_CURRENT4,
    ERR_INDEX_WIRE2_B_CURRENT5,
    ERR_INDEX_WIRE2_B_CURRENT6,
    ERR_INDEX_WIRE2_C_CURRENT1,
    ERR_INDEX_WIRE2_C_CURRENT2,
    ERR_INDEX_WIRE2_C_CURRENT3,
    ERR_INDEX_WIRE2_C_CURRENT4,
    ERR_INDEX_WIRE2_C_CURRENT5,
    ERR_INDEX_WIRE2_C_CURRENT6,
    ERR_INDEX_BUS_VOLTAGE1,
    ERR_INDEX_BUS_VOLTAGE2,
    ERR_INDEX_BUS_VOLTAGE3,
    ERR_INDEX_BUS_VOLTAGE4,
    ERR_INDEX_BUS_VOLTAGE5,
    ERR_INDEX_BUS_VOLTAGE6
};

enum T_LogDataType {
    LOG_TYPE_FIRST = 0,  //First ID
    LOG_TYPE_STT = 0,    //Short-Term Trend Log
    LOG_TYPE_LGT = 1,    //Long-Term Trend Log
    LOG_TYPE_ACT = 2,    //Activity Log
    LOG_TYPE_REL = 3,    //60 seconds Real time data every 30 days
    LOG_TYPE_NUM = 4,    //Number of logs
    LOG_TYPE_NEXT = 0x8000,
    LOG_TYPE_STTN = LOG_TYPE_STT | LOG_TYPE_NEXT,//Next Short Trend relative to the given handle.
    LOG_TYPE_LGTN = LOG_TYPE_LGT | LOG_TYPE_NEXT,//Next Long Trend relative to the given handle.
    LOG_TYPE_ACTN = LOG_TYPE_ACT | LOG_TYPE_NEXT,//Next Activity Log relative to the given handle.
    LOG_TYPE_RELN = LOG_TYPE_REL | LOG_TYPE_NEXT,//Next Real Time Log relative to the given handle.
};

enum T_ResetCause {
    RESET_NULL = 0,
    RESET_POWERON,
    RESET_WDT
};

enum T_TxnType {
    TX_ONLY = 0,
    TXRX
};

class CommunicationProtocol
{
public:
    CommunicationProtocol();
    virtual ~CommunicationProtocol();
    bool Unpack(unsigned char *data, int &len, unsigned char *des, int des_len);
    void MoveData(unsigned char *data, int data_size, int begin);
    uint16_t Crc16(uint16_t initCrc16, uint8_t *pDataBuf, uint16_t byteCount);
    float calculatePressure(S200RealtimeData sensorData);
public:

    unsigned char mPRPacket[PR_PACKET_LEN];
};

#endif // COMMUNICATIONPROTOCOL_H
