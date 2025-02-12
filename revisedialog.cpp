#include "revisedialog.h"
#include "./ui_revisedialog.h"

ReviseDialog::ReviseDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReviseDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    env();
}

ReviseDialog::~ReviseDialog()
{
    delete ui;
}

void ReviseDialog::env() {
    init();
}

void ReviseDialog::init() {
    Utils::lineEditBorder(this);
    Utils::windowMinMaxButtonsHint(this);
}

void ReviseDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void ReviseDialog::on_pushButton_ReviseCoordinates_clicked()
{

}


void ReviseDialog::on_pushButton_SettingParameter_clicked()
{

}


void ReviseDialog::on_pushButton_ReadData_clicked()
{

}


void ReviseDialog::on_pushButton_SingleStep_clicked()
{

}


