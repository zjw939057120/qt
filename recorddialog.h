#ifndef RECORDDIALOG_H
#define RECORDDIALOG_H

#include <QDialog>
#include "Utils.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class RecordDialog;
}
QT_END_NAMESPACE

class RecordDialog : public QDialog
{
    Q_OBJECT

public:
    RecordDialog(QWidget *parent = nullptr);
    ~RecordDialog();
    void init();
    void retranslateUi();

private:
    Ui::RecordDialog *ui;
    QWidget *m_MainWindow;
};
#endif // RECORDDIALOG_H
