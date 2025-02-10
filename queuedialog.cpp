#include "queuedialog.h"
#include "./ui_queuedialog.h"
#include "mainwindow.h"

QueueDialog::QueueDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QueueDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    init();
}

QueueDialog::~QueueDialog()
{
    delete ui;
}

void QueueDialog::init() {

}

void QueueDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void QueueDialog::on_pushButton_AddData_clicked()
{
    ((MainWindow*)m_MainWindow)->m_QueueSettingDialog->show();
}


void QueueDialog::on_pushButton_StartAnalyze_clicked()
{

}



void QueueDialog::on_pushButton_StopAnalyze_clicked()
{

}
