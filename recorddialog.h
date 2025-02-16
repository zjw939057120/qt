#ifndef RECORDDIALOG_H
#define RECORDDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
    class RecordDialog;
}
QT_END_NAMESPACE

class RecordDialog : public QDialog {
Q_OBJECT

public:
    RecordDialog(QWidget *parent = nullptr);

    ~RecordDialog();

    void Init();

    void retranslateUi();

private slots:

    void on_pushButton_Close_clicked();

public:
    Ui::RecordDialog *ui;
    QWidget *m_MainWindow;
};

#endif // RECORDDIALOG_H
