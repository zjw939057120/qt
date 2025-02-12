#ifndef REVISEDIALOG_H
#define REVISEDIALOG_H

#include <QDialog>
#include "Toolkit.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ReviseDialog;
}
QT_END_NAMESPACE

class ReviseDialog : public QDialog
{
    Q_OBJECT

public:
    ReviseDialog(QWidget *parent = nullptr);
    ~ReviseDialog();
    void InitEnv();
    void Init();
    void retranslateUi();

private slots:
    void on_pushButton_ReviseCoordinates_clicked();

    void on_pushButton_SettingParameter_clicked();

    void on_pushButton_ReadData_clicked();

    void on_pushButton_SingleStep_clicked();

private:
    Ui::ReviseDialog *ui;
    QWidget *m_MainWindow;
};
#endif // REVISEDIALOG_H
