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
    static void LineEditBorder(QWidget *qWidget);

    static void MinMaxButtonsHint(QWidget *qWidget);

    static void WriteLogFile(const char *message);

    static void CreatePath(const char *path);

    static uint8_t ReadFile(const char *path, unsigned char *buff, unsigned long nlen);

    static uint8_t ReadConfigFile(const char *Path, float *nValue);

    static short GetMethodAddr(char *name);

    static unsigned char CreateUart(unsigned char nPort, int nBaut);

    static void UartSendBuff(unsigned char *buff, unsigned short nlen);

    static unsigned short UartRecvBuff(unsigned char *buff);

};

#endif //WIDGET_TOOLKIT_H
