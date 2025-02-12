#ifndef METHODDIALOG_H
#define METHODDIALOG_H

#include <QDialog>
#include "Utils.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MethodDialog;
}
QT_END_NAMESPACE

class MethodDialog : public QDialog
{
    Q_OBJECT

public:
    MethodDialog(QWidget *parent = nullptr);
    ~MethodDialog();
    void env();
    void init();
    void retranslateUi();

private slots:
    void on_pushButton_Save_clicked();

    void on_pushButton_Stage_clicked();

private:
    Ui::MethodDialog *ui;
    QWidget *m_MainWindow;
};
#endif // METHODDIALOG_H
