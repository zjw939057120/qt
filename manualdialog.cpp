#include "manualdialog.h"
#include "ui_manualdialog.h"
#include "mydefine.h"
#include "Toolkit.h"
#include "mainwindow.h"

ManualDialog::ManualDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::ManualDialog) {
    ui->setupUi(this);
    m_MainWindow = parent;
    Init();
}

ManualDialog::~ManualDialog() {
    delete ui;
}

void ManualDialog::RetranslateUi() {
    ui->retranslateUi(this);
}

void ManualDialog::Init() {
    ((MainWindow *) m_MainWindow)->m_Toolkit->LineEditBorder(this);
    ((MainWindow *) m_MainWindow)->m_Toolkit->MinMaxButtonsHint(this);
}

void ManualDialog::on_pushButton_Close_clicked() {
    close();
}

