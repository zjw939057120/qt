#ifndef QUEUEDIALOG_H
#define QUEUEDIALOG_H

#include <QDialog>
#include "include/QToolkit.h"
#include "QueueDialogEx.h"
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
    void InitEnv();
    void Init();
    void retranslateUi();


private slots:
    void on_pushButton_AddData_clicked();

    void on_pushButton_StartAnalyze_clicked();

    void on_pushButton_StopAnalyze_clicked();

private:
    Ui::QueueDialog *ui;
    QWidget *m_MainWindow;
    QueueDialogEx *m_QueueDialogEx;
};
#endif // QUEUEDIALOG_H
