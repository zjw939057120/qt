#include "faqdialog.h"
#include "./ui_faqdialog.h"

FAQDialog::FAQDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FAQDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    init();
}

FAQDialog::~FAQDialog()
{
    delete ui;
}

void FAQDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void FAQDialog::init() {

}
