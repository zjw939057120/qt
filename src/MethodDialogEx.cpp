//
// Created by Administrator on 2025/2/15.
//

#include "MethodDialogEx.h"
#include "Toolkit.h"
#include "mydefine.h"

MethodDialogEx::MethodDialogEx(QWidget *parent) {
    Init();
}

void MethodDialogEx::Init() {

}

//=============================================
//	通过名称找到对应的设备ID号
//=============================================
short GetMethodAddr(char* name)
{
    int i;
    std::string temp1, temp2;

    temp1 = name;
    for (i = 0; i < METHOD_TOTAL; i++)
    {
        temp2 = MethodDlg[i].Name;
        if (MethodDlg[i].Valid)
        {
            if (temp1 == temp2)	return i;
        }
    }

    return -1;
}

