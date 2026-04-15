#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<vector>
#include <QSystemTrayIcon>
#include <QStyle>
#include <qlabel.h>
#include"qtimer.h"
#include"qdatetime.h"
#include <QCloseEvent>
#include "../../Models/Scheduler.hpp"
#include "../../Algorithms/RoundRobin.hpp"
#include "../../Algorithms/SJFp.hpp"
#include "../../Algorithms/SJF.hpp"

#include <qmovie.h>
#include <qcombobox.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    // --- MODERN DARK THEME ---
    QString modernTheme = R"(
        QMainWindow {
            background-color: #1e1e2e; /* Dark sleek background */
        }
        QLabel {
            color: #cdd6f4; /* Soft white text */
            font-size: 14px;
            font-weight: 500;
        }
        QPushButton {
            background-color: #89b4fa; /* Modern blue accent */
            color: #11111b; /* Dark text on buttons for contrast */
            border-radius: 6px; /* Smooth rounded corners */
            padding: 8px 16px;
            font-weight: bold;
            font-size: 14px;
            border: none;
        }
        QPushButton:hover {
            background-color: #b4befe; /* Lighter blue when hovering */
        }
        QPushButton:pressed {
            background-color: #74c7ec; /* Different blue when clicking */
        }
        /* Style the inputs and dropdowns */
        QLineEdit, QComboBox, QSpinBox {
            background-color: #313244;
            color: #cdd6f4;
            border: 1px solid #45475a;
            border-radius: 5px;
            padding: 6px 10px;
            font-size: 13px;
        }
        QLineEdit:focus, QComboBox:focus, QSpinBox:focus {
            border: 2px solid #89b4fa; /* Blue glow when typing */
        }
        /* Beautiful Table Styling */
        QTableWidget {
            background-color: #1e1e2e;
            color: #cdd6f4;
            gridline-color: #313244;
            border: 1px solid #45475a;
            border-radius: 8px;
            selection-background-color: #45475a; /* Highlight color */
        }
        QHeaderView::section {
            background-color: #313244;
            color: #cdd6f4;
            padding: 6px;
            border: none;
            border-bottom: 2px solid #89b4fa; /* Blue underline on headers */
            font-weight: bold;
            font-size: 13px;
        }
        /* Style the scroll area for the Gantt Chart */
        QScrollArea {
            border: 1px solid #45475a;
            border-radius: 8px;
            background-color: #1e1e2e;
        }
        QScrollArea > QWidget > QWidget {
            background-color: transparent; /* Makes the Gantt background blend in */
        }
    )";

    this->setStyleSheet(modernTheme);
    // ---------------------------
    livetimer=new QTimer(this);
    connect(livetimer,&QTimer::timeout,this,&MainWindow::ontick);
    ui->timeQuantumSpin->setEnabled(false);
    ui->PriorityBox->setEnabled(false);
    connect(ui->schedulerTypeCombo,&QComboBox::currentTextChanged,this,[this](const QString&text){
        if(text=="Round Robin"){
            ui->timeQuantumSpin->setEnabled(true);
            ui->PriorityBox->setEnabled(false);

        }
        else if (text=="Priority(Preemptive)"||text=="Priority(Non-Preemptive)")
        {
            ui->PriorityBox->setEnabled(true);
            ui->timeQuantumSpin->setEnabled(false);
        }
        else {
            ui->timeQuantumSpin->setEnabled(false);
            ui->PriorityBox->setEnabled(false);
        }
    });


}
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_LiveButton_clicked(){
    ui->timeLabel->setText("Time: 0 s");
    if(liveScheduler!=nullptr){
        delete liveScheduler;
        liveScheduler=nullptr;
    }
    QString type=ui->schedulerTypeCombo->currentText();
    if(type=="Round Robin"){
        liveScheduler=new RoundRobin(ui->timeQuantumSpin->value());
    }else if(type=="FCFS"){

    }else if(type=="SJF(Preemptive)")
    {
        liveScheduler=new sjfp();
    }
    else if(type=="SJF(Non-Preemptive)"){
        liveScheduler=new sjf();
    }else if(type=="Priority(Preemptive)"){
    }else if(type=="Priority(Non-Preemptive)"){
    }


    // clear the old gantt chart
    if(ui->ganttScrollArea->widget()->layout() == nullptr){
        QHBoxLayout* layout = new QHBoxLayout(ui->ganttScrollArea->widget());
        layout->setAlignment(Qt::AlignLeft);
    }
    QLayoutItem *child;
    while ((child = ui->ganttScrollArea->widget()->layout()->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
    last_gantt_pid = -2;
    current_gantt_label = nullptr;
    currenttime=0;
    //make the  sorter empty
    while(!sorter.empty())sorter.getNext();
    for(const auto&p:processlist)sorter.addProcess_sorted(p);
    sorter.transferToScheduler(*liveScheduler,currenttime);
    //start the ticking timer to run every 1000 milliseconds (1 second)
    livetimer->start(1000);
}


void MainWindow::on_AddProcessButton_clicked(){
    int id=ui->ProcessIdBox->text().toInt();
    int arr=ui->ArriveTimeBox->text().toInt();
    int burst=ui->BurstTimeBox->text().toInt();
    int prio=ui->PriorityBox->text().toInt();
    Process p(id,arr,burst,prio);
    processlist.push_back(p);
    sorter.addProcess_sorted(p);
    int row=ui->processTable->rowCount();
    ui->processTable->insertRow(row);
    ui->processTable->setItem(row,0,new QTableWidgetItem(QString::number(id)));
    ui->processTable->setItem(row,1,new QTableWidgetItem(QString::number(arr)));
    ui->processTable->setItem(row,2,new QTableWidgetItem(QString::number(burst)));
    ui->processTable->setItem(row,3,new QTableWidgetItem(QString::number(prio)));
    ui->processTable->setItem(row,4,new QTableWidgetItem(QString::number(burst)));
    ui->ProcessIdBox->clear();
    ui->ArriveTimeBox->clear();
    ui->BurstTimeBox->clear();
    ui->PriorityBox->clear();
    if(liveScheduler!=nullptr&&!livetimer->isActive())livetimer->start(1000);
}



void MainWindow::ontick(){
    sorter.transferToScheduler(*liveScheduler,currenttime);
    int pid=liveScheduler->Schdule();
    if(pid!=-1){
        for(int i=0;i<ui->processTable->rowCount();++i){
            if(ui->processTable->item(i,0)->text().toInt()==pid){
                int rem=ui->processTable->item(i,4)->text().toInt();
                if(rem>0)ui->processTable->setItem(i,4,new QTableWidgetItem(QString::number(rem-1)));
                break;
            }
        }
    }
    // --- GANTT CHART LOGIC ---
    // if the cpu switched to a different process (or switched to idle)
    if (pid != last_gantt_pid) {
        current_block_start = currenttime;
        current_gantt_label = new QLabel();
        current_gantt_label->setMinimumSize(50, 40); // base size for 1 second
        current_gantt_label->setAlignment(Qt::AlignCenter);

        if (pid == -1) {
            // CPU is idle
            current_gantt_label->setStyleSheet("background-color: #dddddd; border: 1px solid black;");
            current_gantt_label->setText(QString("Idle\n%1 - %2").arg(current_block_start).arg(currenttime + 1));
        } else {
            // CPU is running a process. Give it a unique color based on its ID
            int hue = (pid * 47) % 360;
            current_gantt_label->setStyleSheet(QString("background-color: hsv(%1, 150, 250); border: 1px solid black; font-weight: bold;").arg(hue));
            current_gantt_label->setText(QString("P%1\n%2 - %3").arg(pid).arg(current_block_start).arg(currenttime + 1));
        }

        // add the new block to the scroll area
        ui->ganttScrollArea->widget()->layout()->addWidget(current_gantt_label);
        last_gantt_pid = pid;
    }
    // if the SAME process is still running
    else {
        if (current_gantt_label != nullptr) {
            // calculate how long it has been running
            int duration = (currenttime + 1) - current_block_start;
            // visually stretch the block by 50 pixels per second
            current_gantt_label->setMinimumWidth(duration * 50);

            // update the end time text
            if (pid == -1) {
                current_gantt_label->setText(QString("Idle\n%1 - %2").arg(current_block_start).arg(currenttime + 1));
            } else {
                current_gantt_label->setText(QString("P%1\n%2 - %3").arg(pid).arg(current_block_start).arg(currenttime + 1));
            }
        }
    }
    // -------------------------
    currenttime++;
    ui->timeLabel->setText("Time: " + QString::number(currenttime) + " s");
    if(sorter.empty()&&liveScheduler->isFinished())livetimer->stop();
}

void MainWindow::on_ResetButton_clicked()
{
    livetimer->stop();
    ui->timeLabel->setText("Time: 0 s");
    if(liveScheduler!=nullptr){
        delete liveScheduler;
        liveScheduler=nullptr;
    }
    // clear the old gantt chart
    if(ui->ganttScrollArea->widget()->layout() == nullptr){
        QHBoxLayout* layout = new QHBoxLayout(ui->ganttScrollArea->widget());
        layout->setAlignment(Qt::AlignLeft);
    }
    QLayoutItem *child;
    while ((child = ui->ganttScrollArea->widget()->layout()->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
    last_gantt_pid = -2;
    current_gantt_label = nullptr;
    currenttime=0;

    while(!sorter.empty())sorter.getNext();

    processlist.clear();

    ui->processTable->setRowCount(0);

    ui->ProcessIdBox->clear();
    ui->ArriveTimeBox->clear();
    ui->BurstTimeBox->clear();
    ui->PriorityBox->clear();
}


void MainWindow::on_StaticButton_clicked()
{
    livetimer->stop();
    if(liveScheduler!=nullptr){
        delete liveScheduler;
        liveScheduler=nullptr;
    }
    QString type=ui->schedulerTypeCombo->currentText();
    if(type=="Round Robin"){
        liveScheduler=new RoundRobin(ui->timeQuantumSpin->value());
    }else if(type=="FCFS"){
    }else if(type=="SJF(Preemptive)"){
        liveScheduler=new sjfp();
    }else if(type=="SJF(Non-Preemptive)"){
        liveScheduler=new sjf();
    }else if(type=="Priority(Preemptive)"){
    }else if(type=="Priority(Non-Preemptive)"){
    }
    if(liveScheduler==nullptr)return;
    if(ui->ganttScrollArea->widget()->layout()==nullptr){
        QHBoxLayout*layout=new QHBoxLayout(ui->ganttScrollArea->widget());
        layout->setAlignment(Qt::AlignLeft);
    }
    QLayoutItem*child;
    while((child=ui->ganttScrollArea->widget()->layout()->takeAt(0))!=nullptr){
        delete child->widget();
        delete child;
    }
    last_gantt_pid=-2;
    current_gantt_label=nullptr;
    currenttime=0;
    while(!sorter.empty())sorter.getNext();
    for(const auto&p:processlist)sorter.addProcess_sorted(p);
    while(!(sorter.empty()&&liveScheduler->isFinished())){
        sorter.transferToScheduler(*liveScheduler,currenttime);
        int pid=liveScheduler->Schdule();
        if(pid!=-1){
            for(int i=0;i<ui->processTable->rowCount();++i){
                if(ui->processTable->item(i,0)->text().toInt()==pid){
                    int rem=ui->processTable->item(i,4)->text().toInt();
                    if(rem>0)ui->processTable->setItem(i,4,new QTableWidgetItem(QString::number(rem-1)));
                    break;
                }
            }
        }
        if(pid!=last_gantt_pid){
            current_block_start=currenttime;
            current_gantt_label=new QLabel();
            current_gantt_label->setMinimumSize(50,40);
            current_gantt_label->setAlignment(Qt::AlignCenter);
            if(pid==-1){
                current_gantt_label->setStyleSheet("background-color:#dddddd;border:1px solid black;");
                current_gantt_label->setText(QString("idle\n%1-%2").arg(current_block_start).arg(currenttime+1));
            }else{
                int hue=(pid*47)%360;
                current_gantt_label->setStyleSheet(QString("background-color:hsv(%1,150,250);border:1px solid black;font-weight:bold;").arg(hue));
                current_gantt_label->setText(QString("p%1\n%2-%3").arg(pid).arg(current_block_start).arg(currenttime+1));
            }
            ui->ganttScrollArea->widget()->layout()->addWidget(current_gantt_label);
            last_gantt_pid=pid;
        }else{
            if(current_gantt_label!=nullptr){
                int duration=(currenttime+1)-current_block_start;
                current_gantt_label->setMinimumWidth(duration*50);
                if(pid==-1){
                    current_gantt_label->setText(QString("idle\n%1-%2").arg(current_block_start).arg(currenttime+1));
                }else{
                    current_gantt_label->setText(QString("p%1\n%2-%3").arg(pid).arg(current_block_start).arg(currenttime+1));
                }
            }
        }
        currenttime++;
    }
    ui->timeLabel->setText("time:"+QString::number(currenttime)+"s");
}


