//
// Created by zjw93 on 2025/2/11.
//

#ifndef WIDGET_TOOLKIT_H
#define WIDGET_TOOLKIT_H

#include <QWidget>
#include <QMessageBox>

#define  DATA_PATH "Data"
#define  SETTING_FILE_PATH "Data/System.ini"
#define  METHOD_FILE_PATH  "Data/Method.bin"
#define  QUEUE_FILE_PATH "Data/Queue.bin"
#define  LOG_PATH "Log"
#define  LOG_FILE_PATH "Log/Log-%1.txt"

class Toolkit {

public:
    static void LineEditBorder(QWidget *qWidget);

    static void MinMaxButtonsHint(QWidget *qWidget);

    static void WriteLogFile(const char *message);

    static void CreatePath(const char *path);

    static uint8_t ReadFile(const char *path, unsigned char *buff, unsigned long nlen);

    static uint8_t ReadConfigFile(const char *Path, float *nValue);

    static short GetMethodAddr(char* name);
};


#endif //WIDGET_TOOLKIT_H
