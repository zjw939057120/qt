#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aboutdialog.h"
#include "faqdialog.h"
#include "manualdialog.h"
#include "methoddialog.h"
#include "queuedialog.h"
#include "queuesettingdialog.h"
#include "recorddialog.h"
#include "revisedialog.h"
#include "sampledialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void env();

    void init();

    void retranslateUi(const QString &lang);

private slots:

    void on_actionMethod_triggered();

    void on_actionQueue_triggered();

    void on_actionSample_triggered();

    void on_actionRecord_triggered();

    void on_actionQuit_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionEnglish_triggered();

    void on_actionChinese_triggered();

    void on_actionRevise_triggered();

    void on_actionManual_triggered();

    void on_actionFAQ_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;

public:
    AboutDialog *m_AboutDialog;
    FAQDialog *m_FAQDialog;
    ManualDialog *m_ManualDialog;
    MethodDialog *m_MethodDialog;
    QueueDialog *m_QueueDialog;
    QueueSettingDialog *m_QueueSettingDialog;
    RecordDialog *m_RecordDialog;
    ReviseDialog *m_ReviseDialog;
    SampleDialog *m_SampleDialog;
};

#endif // MAINWINDOW_H
