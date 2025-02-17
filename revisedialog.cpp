#include "revisedialog.h"
#include "ui_revisedialog.h"
#include "mydefine.h"
#include "Toolkit.h"
#include "mainwindow.h"

ReviseDialog::ReviseDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::ReviseDialog) {
    ui->setupUi(this);
    m_MainWindow = parent;
    Init();
}

ReviseDialog::~ReviseDialog() {
    delete ui;
}

void ReviseDialog::Init() {
    ((MainWindow *) m_MainWindow)->m_Toolkit->LineEditBorder(this);
    ((MainWindow *) m_MainWindow)->m_Toolkit->MinMaxButtonsHint(this);
}

void ReviseDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void ReviseDialog::on_pushButton_ReviseCoordinates_clicked() {

}


void ReviseDialog::on_pushButton_SettingParameter_clicked() {

}


void ReviseDialog::on_pushButton_ReadData_clicked() {

}


void ReviseDialog::on_pushButton_SingleStep_clicked() {

}


