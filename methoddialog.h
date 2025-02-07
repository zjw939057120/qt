#ifndef METHODDIALOG_H
#define METHODDIALOG_H

#include <QDialog>

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
    void retranslateUi();

private:
    Ui::MethodDialog *ui;
};
#endif // METHODDIALOG_H
