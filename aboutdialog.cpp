#include <QTranslator>
#include "aboutdialog.h"
#include "./ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    env();
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void AboutDialog::env() {
    init();
}

void AboutDialog::init() {
    Utils::lineEditBorder(this);

}

void AboutDialog::on_pushButton_Close_clicked()
{
    close();
}
