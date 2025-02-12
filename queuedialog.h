#ifndef QUEUEDIALOG_H
#define QUEUEDIALOG_H

#include <QDialog>
#include "Utils.h"
#include "queuesettingdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class QueueDialog;
}
QT_END_NAMESPACE

class QueueDialog : public QDialog
{
    Q_OBJECT

public:
    QueueDialog(QWidget *parent = nullptr);
    ~QueueDialog();
    void env();
    void init();
    void retranslateUi();


private slots:
    void on_pushButton_AddData_clicked();

    void on_pushButton_StartAnalyze_clicked();

    void on_pushButton_StopAnalyze_clicked();

private:
    Ui::QueueDialog *ui;
    QWidget *m_MainWindow;
};
#endif // QUEUEDIALOG_H
