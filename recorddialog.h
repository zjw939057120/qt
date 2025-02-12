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
    void env();
    void init();
    void retranslateUi();

private slots:
    void on_pushButton_Close_clicked();

private:
    Ui::RecordDialog *ui;
    QWidget *m_MainWindow;
};
#endif // RECORDDIALOG_H
