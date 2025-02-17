//
// Created by zjw93 on 2025/2/11.
//

#ifndef WIDGET_TOOLKIT_H
#define WIDGET_TOOLKIT_H

#include <QWidget>
#include <QMessageBox>
#include <QSerialPort>
#include <QSerialPortInfo>

#define  CONFIG_PATH "Config"
#define  CONFIG_PATH_DATA "Config/System.ini"
#define  QUEUE_PATH "Queue"
#define  QUEUE_PATH_DATA "Queue/QueueFile.bin"
#define  METHOD_PATH "Method"
#define  METHOD_PATH_DATA  "Method/MethodFile.bin"
#define  LOG_PATH "Log"
#define  LOG_PATH_DATA "Log/Log-%1.txt"
#define  REPORT_PATH "Report"
#define  WAVE_PATH "Wave"

class Toolkit {

public:
    Toolkit(QWidget *parent = nullptr);

    void LineEditBorder(QWidget *qWidget);

    void MinMaxButtonsHint(QWidget *qWidget);

    static void WriteLogFile(const char *message);

    void CreatePath(const char *path);

    uint8_t ReadFile(const char *path, unsigned char *buff, unsigned long nlen);

    uint8_t ReadConfigFile(const char *Path, float *nValue);

    static short GetMethodAddr(char *name);

    unsigned char CreateUart(unsigned char nPort, int nBaut);

    void UartSendBuff(unsigned char *buff, unsigned short nlen);

    unsigned short UartRecvBuff(unsigned char *buff);

public:
    QSerialPort *m_SerialPort = nullptr;
};

#endif //WIDGET_TOOLKIT_H
