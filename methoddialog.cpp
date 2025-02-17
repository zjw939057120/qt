#include "methoddialog.h"
#include "ui_methoddialog.h"
#include "mydefine.h"
#include "Toolkit.h"
#include "mainwindow.h"

MethodDialog::MethodDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::MethodDialog) {
    ui->setupUi(this);
    m_MainWindow = parent;
    Init();
}

MethodDialog::~MethodDialog() {
    delete ui;
}

void MethodDialog::Init() {
    ((MainWindow *) m_MainWindow)->m_Toolkit->LineEditBorder(this);
    ((MainWindow *) m_MainWindow)->m_Toolkit->MinMaxButtonsHint(this);
}

void MethodDialog::RetranslateUi() {
    ui->retranslateUi(this);
}

void MethodDialog::on_pushButton_Save_clicked() {
    close();
}

void MethodDialog::on_pushButton_Stage_clicked() {
    close();
}

