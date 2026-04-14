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

#include <qmovie.h>
#include <qcombobox.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
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
    if(liveScheduler!=nullptr){
        delete liveScheduler;
        liveScheduler=nullptr;
    }
    QString type=ui->schedulerTypeCombo->currentText();
    if(type=="Round Robin"){
        liveScheduler=new RoundRobin(ui->timeQuantumSpin->value());
    }else if(type=="FCFS"){
    }else if(type=="SJF(Preemptive)"){
    }else if(type=="SJF(Non-Preemptive)"){
    }else if(type=="Priority(Preemptive)"){
    }else if(type=="Priority(Non-Preemptive)"){
    }
    if(liveScheduler==nullptr)return;
    currenttime=0;
    processesadded=0;
    for(const auto&p:processlist){
        if(p.getArrival()==0){
            liveScheduler->addProcess(p);
            processesadded++;
        }
    }
    livetimer->start(1000);
}

void MainWindow::ontick(){
    if(currenttime>0){
        for(const auto&p:processlist){
            if(p.getArrival()==currenttime){
                liveScheduler->addProcess(p);
                processesadded++;
            }
        }
    }
    int pid=liveScheduler->Schdule();
    if(pid!=-1){
        for(int i=0;i<ui->processtable->rowCount();++i){
            if(ui->processtable->item(i,0)->text().toInt()==pid){
                int rem=ui->processtable->item(i,4)->text().toInt();
                if(rem>0){
                    ui->processtable->setItem(i,4,new QTableWidgetItem(QString::number(rem-1)));
                }
                break;
            }
        }
    }
    currenttime++;
    if(processesadded==processlist.size()&&liveScheduler->isFinished()){
        livetimer->stop();
    }
}

