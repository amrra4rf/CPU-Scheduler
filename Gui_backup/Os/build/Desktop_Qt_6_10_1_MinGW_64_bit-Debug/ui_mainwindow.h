/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *schedulerTypeCombo;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *timeQuantumSpin;
    QFrame *line;
    QLabel *label_3;
    QFrame *line_2;
    QLineEdit *ProcessIdBox;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *ArriveTimeBox;
    QLineEdit *BurstTimeBox;
    QLineEdit *PriorityBox;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *line_3;
    QPushButton *AddProcessButton;
    QFrame *line_4;
    QLabel *label_8;
    QTableWidget *processTable;
    QScrollArea *ganttScrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QLabel *timeLabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *StaticButton;
    QPushButton *LiveButton;
    QPushButton *ResetButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(909, 642);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        schedulerTypeCombo = new QComboBox(centralwidget);
        schedulerTypeCombo->addItem(QString());
        schedulerTypeCombo->addItem(QString());
        schedulerTypeCombo->addItem(QString());
        schedulerTypeCombo->addItem(QString());
        schedulerTypeCombo->addItem(QString());
        schedulerTypeCombo->addItem(QString());
        schedulerTypeCombo->setObjectName("schedulerTypeCombo");
        schedulerTypeCombo->setGeometry(QRect(130, 30, 211, 28));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 111, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(510, 30, 111, 31));
        timeQuantumSpin = new QSpinBox(centralwidget);
        timeQuantumSpin->setObjectName("timeQuantumSpin");
        timeQuantumSpin->setGeometry(QRect(640, 30, 91, 29));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(-10, 60, 1061, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 80, 161, 31));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        label_3->setFont(font);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(310, 70, 41, 271));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        ProcessIdBox = new QLineEdit(centralwidget);
        ProcessIdBox->setObjectName("ProcessIdBox");
        ProcessIdBox->setGeometry(QRect(100, 130, 221, 28));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 120, 91, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 170, 81, 20));
        ArriveTimeBox = new QLineEdit(centralwidget);
        ArriveTimeBox->setObjectName("ArriveTimeBox");
        ArriveTimeBox->setGeometry(QRect(100, 170, 221, 28));
        BurstTimeBox = new QLineEdit(centralwidget);
        BurstTimeBox->setObjectName("BurstTimeBox");
        BurstTimeBox->setGeometry(QRect(100, 210, 221, 28));
        PriorityBox = new QLineEdit(centralwidget);
        PriorityBox->setObjectName("PriorityBox");
        PriorityBox->setGeometry(QRect(100, 250, 221, 28));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 210, 81, 20));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 250, 81, 31));
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(0, 330, 1011, 16));
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        AddProcessButton = new QPushButton(centralwidget);
        AddProcessButton->setObjectName("AddProcessButton");
        AddProcessButton->setGeometry(QRect(130, 300, 111, 29));
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(0, 383, 991, 20));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 390, 181, 51));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        label_8->setFont(font1);
        processTable = new QTableWidget(centralwidget);
        if (processTable->columnCount() < 5)
            processTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        processTable->setObjectName("processTable");
        processTable->setGeometry(QRect(340, 80, 541, 251));
        ganttScrollArea = new QScrollArea(centralwidget);
        ganttScrollArea->setObjectName("ganttScrollArea");
        ganttScrollArea->setGeometry(QRect(50, 450, 741, 111));
        ganttScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 739, 109));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setObjectName("horizontalLayout");
        ganttScrollArea->setWidget(scrollAreaWidgetContents);
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setGeometry(QRect(800, 500, 131, 20));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(100, 350, 741, 31));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        StaticButton = new QPushButton(widget);
        StaticButton->setObjectName("StaticButton");

        horizontalLayout_2->addWidget(StaticButton);

        LiveButton = new QPushButton(widget);
        LiveButton->setObjectName("LiveButton");

        horizontalLayout_2->addWidget(LiveButton);

        ResetButton = new QPushButton(widget);
        ResetButton->setObjectName("ResetButton");

        horizontalLayout_2->addWidget(ResetButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 909, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        schedulerTypeCombo->setItemText(0, QCoreApplication::translate("MainWindow", "FCFS", nullptr));
        schedulerTypeCombo->setItemText(1, QCoreApplication::translate("MainWindow", "SJF(Preemptive)", nullptr));
        schedulerTypeCombo->setItemText(2, QCoreApplication::translate("MainWindow", "SJF(Non-Preemptive)", nullptr));
        schedulerTypeCombo->setItemText(3, QCoreApplication::translate("MainWindow", "Priority(Preemptive)", nullptr));
        schedulerTypeCombo->setItemText(4, QCoreApplication::translate("MainWindow", "Priority(Non-Preemptive)", nullptr));
        schedulerTypeCombo->setItemText(5, QCoreApplication::translate("MainWindow", "Round Robin", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Scheduler Type", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Quantum Time", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Add Process ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Process ID", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Arrive Time", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Burst Time", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Priority", nullptr));
        AddProcessButton->setText(QCoreApplication::translate("MainWindow", "Add Process", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Gantt Chart", nullptr));
        QTableWidgetItem *___qtablewidgetitem = processTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "PId", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = processTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Arrival Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = processTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Burst Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = processTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Priority", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = processTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Remaining Time", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWindow", "Time: 0 s", nullptr));
        StaticButton->setText(QCoreApplication::translate("MainWindow", "Static Scheduling", nullptr));
        LiveButton->setText(QCoreApplication::translate("MainWindow", "Live Scheduling", nullptr));
        ResetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
