#include "manualdialog.h"
#include "./ui_manualdialog.h"

ManualDialog::ManualDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManualDialog)
{
    ui->setupUi(this);
    m_MainWindow = parent;
    init();
}

ManualDialog::~ManualDialog()
{
    delete ui;
}

void ManualDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void ManualDialog::init() {
    Utils::lineEditBorder(this);

}
