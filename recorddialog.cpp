#include "recorddialog.h"
#include "./ui_recorddialog.h"
#include "Toolkit.h"

RecordDialog::RecordDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::RecordDialog) {
    ui->setupUi(this);
    m_MainWindow = parent;
    m_RecordDialogEx = new RecordDialogEx(parent);
    InitEnv();
}

RecordDialog::~RecordDialog() {
    delete ui;
}

void RecordDialog::InitEnv() {
    Init();
}

void RecordDialog::Init() {
    Toolkit::LineEditBorder(this);
    Toolkit::MinMaxButtonsHint(this);
}

void RecordDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void RecordDialog::on_pushButton_Close_clicked() {
    close();
}

