#ifndef MANUALDIALOG_H
#define MANUALDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class ManualDialog;
}
QT_END_NAMESPACE

class ManualDialog : public QDialog
{
    Q_OBJECT

public:
    ManualDialog(QWidget *parent = nullptr);
    ~ManualDialog();
    void retranslateUi();

private:
    Ui::ManualDialog *ui;
};
#endif // MANUALDIALOG_H
