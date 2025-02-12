#include "manualdialog.h"
#include "./ui_manualdialog.h"

ManualDialog::ManualDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManualDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    env();
}

ManualDialog::~ManualDialog()
{
    delete ui;
}

void ManualDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void ManualDialog::env() {
    init();
}

void ManualDialog::init() {
    Utils::lineEditBorder(this);
    Utils::windowMinMaxButtonsHint(this);
}

void ManualDialog::on_pushButton_Close_clicked()
{
    close();
}

