#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include "include/QToolkit.h"
#include "AboutDialogEx.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class AboutDialog;
}
QT_END_NAMESPACE

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    AboutDialog(QWidget *parent = nullptr);
    ~AboutDialog();
    void InitEnv();
    void Init();
    void retranslateUi();

private slots:
    void on_pushButton_Close_clicked();

private:
    Ui::AboutDialog *ui;
    QWidget *m_MainWindow;
    AboutDialogEx *m_AboutDialogEx;
};
#endif // ABOUTDIALOG_H
