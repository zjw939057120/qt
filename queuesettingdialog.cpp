#include "queuesettingdialog.h"
#include "ui_queuesettingdialog.h"
#include "mydefine.h"
#include "Toolkit.h"
#include "mainwindow.h"

QueueSettingDialog::QueueSettingDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::QueueSettingDialog) {
    ui->setupUi(this);
    m_MainWindow = parent;
    Init();
}

QueueSettingDialog::~QueueSettingDialog() {
    delete ui;
}

void QueueSettingDialog::Init() {
    this->setModal(true);
    ((MainWindow *) m_MainWindow)->m_Toolkit->LineEditBorder(this);
    ((MainWindow *) m_MainWindow)->m_Toolkit->MinMaxButtonsHint(this);
}

void QueueSettingDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void QueueSettingDialog::on_pushButton_Save_clicked() {
    close();
}


void QueueSettingDialog::on_pushButton_Stage_clicked() {
    close();
}
