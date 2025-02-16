#include <QTranslator>
#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include "mydefine.h"
#include "Toolkit.h"

AboutDialog::AboutDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::AboutDialog) {
    ui->setupUi(this);
    m_MainWindow = parent;
    Init();
}

AboutDialog::~AboutDialog() {
    delete ui;
}

void AboutDialog::retranslateUi() {
    ui->retranslateUi(this);
}

void AboutDialog::Init() {
    Toolkit::LineEditBorder(this);

}

void AboutDialog::on_pushButton_Close_clicked() {
    close();
}
