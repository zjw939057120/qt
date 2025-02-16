#include "debugdialog.h"
#include "ui_debugdialog.h"
#include "mydefine.h"
#include "Toolkit.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>

DebugDialog::DebugDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::DebugDialog) {
    ui->setupUi(this);
    m_MainWindow = parent;
    Init();
}

DebugDialog::~DebugDialog() {
    delete ui;
}

void DebugDialog::Init() {
    Toolkit::LineEditBorder(this);
    Toolkit::MinMaxButtonsHint(this);
}

void DebugDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void DebugDialog::WriteLogFile(const char *message) {
    QString msg = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss ").append(message);
#ifdef _DEBUG_ENV
    ui->listWidget->addItem(msg);
#endif

    // 创建日志文件（如果文件不存在则会创建）
    QString name = QString(LOG_PATH_DATA).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    QFile file(name);
    // 以追加模式打开文件
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        // 写入日志，包含时间戳
        out << msg << "\n";
        file.close();  // 关闭文件
    }
}