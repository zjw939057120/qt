#include "methoddialog.h"
#include "./ui_methoddialog.h"
#include "Toolkit.h"

MethodDialog::MethodDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::MethodDialog) {
    ui->setupUi(this);
    m_MainWindow = parent;
    m_MethodDialogEx = new MethodDialogEx(parent);
    Init();
}

MethodDialog::~MethodDialog() {
    delete ui;
}

void MethodDialog::Init() {
    Toolkit::LineEditBorder(this);
    Toolkit::MinMaxButtonsHint(this);
}

void MethodDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void MethodDialog::on_pushButton_Save_clicked() {
    close();
}

void MethodDialog::on_pushButton_Stage_clicked() {
    close();
}

