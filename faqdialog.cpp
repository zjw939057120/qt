#include "faqdialog.h"
#include "./ui_faqdialog.h"

FAQDialog::FAQDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FAQDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    InitEnv();
}

FAQDialog::~FAQDialog()
{
    delete ui;
}

void FAQDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void FAQDialog::InitEnv() {
    Init();
}

void FAQDialog::Init() {
    Toolkit::LineEditBorder(this);
    Toolkit::MinMaxButtonsHint(this);
}

void FAQDialog::on_pushButton_Close_clicked()
{
    close();
}

