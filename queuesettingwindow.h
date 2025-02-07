#ifndef QUEUESETTINGWINDOW_H
#define QUEUESETTINGWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class QueueSettingWindow;
}
QT_END_NAMESPACE

class QueueSettingWindow : public QMainWindow
{
    Q_OBJECT

public:
    QueueSettingWindow(QWidget *parent = nullptr);
    ~QueueSettingWindow();

private:
    Ui::QueueSettingWindow *ui;
};
#endif // QUEUESETTINGWINDOW_H
