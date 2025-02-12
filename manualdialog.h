#ifndef MANUALDIALOG_H
#define MANUALDIALOG_H

#include <QDialog>
#include "Utils.h"

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
    void env();
    void init();
    void retranslateUi();

private:
    Ui::ManualDialog *ui;
    QWidget *m_MainWindow;

};
#endif // MANUALDIALOG_H
