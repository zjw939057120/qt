//
// Created by zjw93 on 2025/2/11.
//

#ifndef WIDGET_TOOLKIT_H
#define WIDGET_TOOLKIT_H


#include <QWidget>
#include "Utils.h"

class Toolkit {

public:
    static void LineEditBorder(QWidget *qWidget);

    static void MinMaxButtonsHint(QWidget *qWidget);

    static void WriteLogFile(const char *message);

    static void CreatePath(const char *path);

    static uint8_t ReadFile(const char *path, unsigned char *buff, unsigned long nlen);

    static uint8_t ReadConfigFile(const char *Path, float *nValue);
};


#endif //WIDGET_TOOLKIT_H
