#include "debugdialog.h"
#include "ui_debugdialog.h"
#include "mydefine.h"
#include "Toolkit.h"
#include "mainwindow.h"
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
    ((MainWindow *) m_MainWindow)->m_Toolkit->LineEditBorder(this);
    ((MainWindow *) m_MainWindow)->m_Toolkit->MinMaxButtonsHint(this);
}

void DebugDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void DebugDialog::WriteLogFile(const char *message) {
    QString msg = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss ").append(message);
#ifdef _DEBUG_ENV
    ui->listWidget->addItem(msg);
#endif
    ((MainWindow *) m_MainWindow)->m_Toolkit->LineEditBorder(this);

    Toolkit::WriteLogFile(msg.toStdString().data());
}