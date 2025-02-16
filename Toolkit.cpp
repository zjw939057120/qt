//
// Created by zjw93 on 2025/2/11.
//

#include "mydefine.h"
#include "Toolkit.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QSettings>

void Toolkit::LineEditBorder(QWidget *qWidget) {
    qWidget->setStyleSheet("QLineEdit { border: none; }");
}

void Toolkit::MinMaxButtonsHint(QWidget *qWidget) {
    qWidget->setWindowFlags(qWidget->windowFlags() & ~Qt::WindowMinMaxButtonsHint);

}


void WriteLogFile(char *nText) {
    // 创建日志文件（如果文件不存在则会创建）
    QString qString = QString(LOG_PATH_DATA).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    QFile file(qString);

    // 以追加模式打开文件
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);

        // 获取当前时间戳
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss ");

        // 写入日志，包含时间戳
        out << currentTime << nText << "\n";

        file.close();  // 关闭文件
    } else {
        qDebug() << "Unable to open log file for writing!";
    }
}

void Toolkit::WriteLogFile(const char *message) {
    // 创建日志文件（如果文件不存在则会创建）
    QString name = QString(LOG_PATH_DATA).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    QFile file(name);

    // 以追加模式打开文件
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);

        // 获取当前时间戳
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss ");

        // 写入日志，包含时间戳
        out << currentTime << message << "\n";

        file.close();  // 关闭文件
    } else {
        qDebug() << "Unable to open log file for writing!";
    }
}

void Toolkit::CreatePath(const char *path) {
    QDir dir;
    // 如果目录不存在，创建目录
    if (dir.mkpath(path)) {
        qDebug() << "Directory created successfully!";
    } else {
        qDebug() << "Failed to create directory!";
    }
}

uint8_t Toolkit::ReadFile(const char *path, unsigned char *buff, unsigned long nlen) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Unable to open file!";
        return 0;
    }

    // 分块读取文件内容
    file.read(reinterpret_cast<char *>(buff), nlen);  // 读取指定大小的块
    file.close();  // 关闭文件
    return 1;
}

uint8_t Toolkit::ReadConfigFile(const char *Path, float *nValue) {
    if (!QFile::exists(Path))
        return 0;
    // 创建 QSettings 实例
    QSettings settings(Path, QSettings::IniFormat);

    for (int i = 0; i < SYSTEM_PARA_TOTAL; ++i) {
        // 读取各个配置项
        QString key = QString("para%1").arg(i);
        nValue[i] = settings.value(key, 0).toFloat();
        Toolkit::WriteLogFile(settings.value(key, 0).toString().toStdString().data());
    }

    return 1;
}

//=============================================
//	通过名称找到对应的设备ID号
//=============================================
short Toolkit::GetMethodAddr(char *name) {
    int i;
    std::string temp1, temp2;

    temp1 = name;
    for (i = 0; i < METHOD_TOTAL; i++) {
        temp2 = MethodDlg[i].Name;
        if (MethodDlg[i].Valid) {
            if (temp1 == temp2) return i;
        }
    }

    return -1;
}
