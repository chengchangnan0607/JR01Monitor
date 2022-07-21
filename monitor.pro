QT += core gui
QT += charts
QT += sql
QT += serialport
QT += serialbus
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += thread exceptions rtti stl
CONFIG += c++11
macx: LIBS += -framework AppKit

unix:!macx: LIBS += -L$$PWD/qBreakpad/lib/ -lqBreakpad

INCLUDEPATH += $$PWD/qBreakpad/include
DEPENDPATH += $$PWD/qBreakpad/include

unix:!macx: PRE_TARGETDEPS += $$PWD/qBreakpad/lib/libqBreakpad.a

# 生成调试信息
QMAKE_CFLAGS_RELEASE += -g
QMAKE_CXXFLAGS_RELEASE += -g

# 禁止优化
QMAKE_CFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE -= -O2

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/UI/dialoghistoricaldata.cpp \
    src/UI/dialoghistoricaldatatimeset.cpp \
    src/UI/dialoginputnumber.cpp \
    src/UI/dialoglog.cpp \
    src/UI/dialogsteppages.cpp \
    src/UI/dialogsystemset.cpp \
    src/UI/mainwindow.cpp \
    src/BL/COMM/communicationprotocol.cpp \
    src/BL/COMM/controllercommunication.cpp \
    src/BL/COMM/serialthread.cpp \
    src/BL/DB/database.cpp \
    src/BL/DB/datasearchthread.cpp \
    src/BL/DB/datastoragethread.cpp

HEADERS += \
    src/UI/dialoghistoricaldata.h \
    src/UI/dialoghistoricaldatatimeset.h \
    src/UI/dialoginputnumber.h \
    src/UI/dialoglog.h \
    src/UI/dialogsteppages.h \
    src/UI/dialogsystemset.h \
    src/UI/mainwindow.h \
    src/BL/COMM/communicationprotocol.h \
    src/BL/COMM/controllercommunication.h \
    src/BL/COMM/serialthread.h \
    src/BL/DB/database.h \
    src/BL/DB/datasearchthread.h \
    src/BL/DB/datastoragethread.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons/resources.qrc

FORMS += \
    src/UI/dialoghistoricaldata.ui \
    src/UI/dialoghistoricaldatatimeset.ui \
    src/UI/dialoginputnumber.ui \
    src/UI/dialoglog.ui \
    src/UI/dialogsteppages.ui \
    src/UI/dialogsystemset.ui \
    src/UI/mainwindow.ui
