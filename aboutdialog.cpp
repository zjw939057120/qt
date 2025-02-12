#include <QTranslator>
#include "aboutdialog.h"
#include "./ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    InitEnv();
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void AboutDialog::InitEnv() {
    Init();
}

void AboutDialog::Init() {
    Toolkit::LineEditBorder(this);

}

void AboutDialog::on_pushButton_Close_clicked()
{
    close();
}
