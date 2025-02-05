#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void changeLanguage(const QString &lang);

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

    void on_actionVersion_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
