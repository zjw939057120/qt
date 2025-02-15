#include "queuesettingdialog.h"
#include "./ui_queuesettingdialog.h"
#include "Toolkit.h"

QueueSettingDialog::QueueSettingDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::QueueSettingDialog) {
    ui->setupUi(this);
    m_MainWindow = parent;
    m_QueueSettingDialogEx = new QueueSettingDialogEx(parent);
    Init();
}

QueueSettingDialog::~QueueSettingDialog() {
    delete ui;
}

void QueueSettingDialog::Init() {
    this->setModal(true);
    Toolkit::LineEditBorder(this);
    Toolkit::MinMaxButtonsHint(this);
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
