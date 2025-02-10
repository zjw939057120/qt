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
    void init();
    void retranslateUi();

private:
    Ui::ManualDialog *ui;
    QWidget *m_MainWindow;

};
#endif // MANUALDIALOG_H
