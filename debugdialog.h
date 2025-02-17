#ifndef DEBUGDIALOG_H
#define DEBUGDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
    class DebugDialog;
}
QT_END_NAMESPACE

class DebugDialog : public QDialog {
Q_OBJECT

public:
    DebugDialog(QWidget *parent = nullptr);

    ~DebugDialog();

    void Init();

    void RetranslateUi();

    void WriteLogFile(const char *message);
private:
    Ui::DebugDialog *ui;
    QWidget *m_MainWindow;
};

#endif // DEBUGDIALOG_H
