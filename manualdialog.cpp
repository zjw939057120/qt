#include "manualdialog.h"
#include "./ui_manualdialog.h"

ManualDialog::ManualDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManualDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    InitEnv();
}

ManualDialog::~ManualDialog()
{
    delete ui;
}

void ManualDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void ManualDialog::InitEnv() {
    Init();
}

void ManualDialog::Init() {
    Toolkit::LineEditBorder(this);
    Toolkit::MinMaxButtonsHint(this);
}

void ManualDialog::on_pushButton_Close_clicked()
{
    close();
}

