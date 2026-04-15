#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QHBoxLayout>
#include <QMainWindow>
#include "../../Models/Scheduler.hpp"
#include "../../Algorithms/RoundRobin.hpp"
#include "../../utils/ProcessSorter.hpp"
#include "../../Algorithms/SJFp.hpp"
#include "../../Algorithms/FCFS.hpp"
#include "../../Algorithms/Priority NonP.hpp"
#include "../../Algorithms/Priotity prem.hpp"
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
    void ontick();

    void on_AddProcessButton_clicked();

    void on_ResetButton_clicked();

    void on_StaticButton_clicked();

    void on_PauseButton_clicked();

private:
    Ui::MainWindow *ui;
    Scheduler* liveScheduler = nullptr;
    int currenttime = 0;
    int processesadded = 0;
    QTimer*livetimer;
    int last_gantt_pid = -2;
    int current_block_start = 0;
    QLabel* current_gantt_label = nullptr;
    ProcessSorter sorter;
    std::vector<Process>processlist;};
#endif // MAINWINDOW_H
