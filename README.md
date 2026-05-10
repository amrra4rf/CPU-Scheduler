# 🖥️ CPU Scheduling Algorithms Simulator

A robust **C++ application** designed to **simulate, visualize, and analyze** various CPU scheduling algorithms.  
This project features a dual interface/experience:

- 🎨 **Graphical User Interface (GUI)** built with **Qt** featuring a modern dark theme
- ⏱️ **Real-Time & Static Simulation Modes** for deep-dive algorithm analysis

---

## 📋 Project Overview

This tool allows users to input operating system processes (with Arrival Time, Burst Time, and Priority) and see exactly how different CPU scheduling algorithms handle them.  
It constructs a dynamic **Gantt Chart** to visualize CPU execution and automatically calculates performance analytics like **Average Waiting Time** and **Average Turnaround Time**.

---

## ✨ Key Features

### ⚙️ 1. Supported Algorithms

- 🟢 **First-Come, First-Served (FCFS)**
- 🟡 **Shortest Job First (SJF)** _(Preemptive & Non-Preemptive)_
- 🔴 **Priority Scheduling** _(Preemptive & Non-Preemptive)_
- 🔵 **Round Robin (RR)** _(Customizable Time Quantum)_

### ⏱️ 2. Dual Simulation Modes

- **Live Mode:** Simulates the CPU clock ticking second-by-second (1-tick). Users can pause time, dynamically inject new processes "on the fly," and watch the CPU react in real-time.
- **Static Mode:** Instantly processes all data and displays the final Gantt chart and calculated averages for immediate analysis.

### 📊 3. Analytics & Visualization

- **Dynamic Gantt Chart:** Auto-scaling, color-coded visual blocks representing CPU execution time and idle periods.
- **Process Tracking:** Live countdown of "Remaining Time" in the data table.
- **Performance Metrics:** Precise calculation of Turnaround and Waiting times once simulations finish.

---

## 📥 Installation (Quick Start)

You do **not** need to install Qt or compile the code to run this application.

1. **Download:** Go to the Releases page and download `CPU_Scheduler.zip`.
2. **Extract:** Unzip the entire folder to a location of your choice.
3. **Run:** Open `CPU_Scheduler.exe` to start the GUI.

---

## 🗂️ Project Structure

```text
CPU-Scheduler/
│
├── GUI/
│   ├── main.cpp
│   ├── mainwindow.cpp
│   ├── mainwindow.h
│   └── mainwindow.ui
│
├── Models/
│   ├── Process.hpp
│   └── Scheduler.hpp
│
├── Algorithms/
│   ├── FCFS.hpp
│   ├── SJF.hpp
│   ├── SJFp.hpp
│   ├── Priority_NonP.hpp
│   ├── Priority_P.hpp
│   └── RoundRobin.hpp
│
└── Utils/
    └── PrioritySorter.hpp
```
# CPU-Scheduler
