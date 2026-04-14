#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../Models/Scheduler.hpp"
#include "../../Algorithms/RoundRobin.hpp"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_LiveButton_clicked();

private:
    Ui::MainWindow *ui;
    Scheduler* liveScheduler = nullptr;
    int current_time = 0;
    int processesAdded = 0;
    QTimer*livetimer;
};
#endif // MAINWINDOW_H
