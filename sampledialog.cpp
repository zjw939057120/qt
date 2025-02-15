#include "sampledialog.h"
#include "./ui_sampledialog.h"
#include "Toolkit.h"

SampleDialog::SampleDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::SampleDialog) {
    ui->setupUi(this);
    m_MainWindow = parent;
    m_SampleDialogEx = new SampleDialogEx(parent);
    InitEnv();
}

SampleDialog::~SampleDialog() {
    delete ui;
}

void SampleDialog::InitEnv() {
    Init();
}

void SampleDialog::Init() {
    Toolkit::LineEditBorder(this);
    Toolkit::MinMaxButtonsHint(this);
}

void SampleDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void SampleDialog::on_pushButton_Close_clicked() {
    close();
}

