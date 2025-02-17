#include "queuedialog.h"
#include "ui_queuedialog.h"
#include "mainwindow.h"
#include "mydefine.h"
#include "Toolkit.h"
#include "mainwindow.h"

QueueDialog::QueueDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::QueueDialog) {
    ui->setupUi(this);
    m_MainWindow = parent;
    Init();
}

QueueDialog::~QueueDialog() {
    delete ui;
}

void QueueDialog::Init() {
    ((MainWindow *) m_MainWindow)->m_Toolkit->LineEditBorder(this);
    ((MainWindow *) m_MainWindow)->m_Toolkit->MinMaxButtonsHint(this);
}

void QueueDialog::RetranslateUi() {
    ui->retranslateUi(this);
}

void QueueDialog::on_pushButton_AddData_clicked() {
    (((MainWindow *) m_MainWindow))->m_QueueSettingDialog->show();
}


void QueueDialog::on_pushButton_StartAnalyze_clicked() {

}


void QueueDialog::on_pushButton_StopAnalyze_clicked() {

}

void QueueDialog::DisplayMode(bool isQueueMode) {
    if (isQueueMode) {
        setWindowTitle(QCoreApplication::translate("QueueDialog", "QueueDialog", nullptr));
        ui->pushButton_AddData->setVisible(true);
        ui->pushButton_StartAnalyze->setVisible(true);
        ui->pushButton_StopAnalyze->setVisible(true);
    } else {
        setWindowTitle(QCoreApplication::translate("RecordDialog", "RecordDialog", nullptr));
        ui->pushButton_AddData->setVisible(false);
        ui->pushButton_StartAnalyze->setVisible(false);
        ui->pushButton_StopAnalyze->setVisible(false);
    }
}
