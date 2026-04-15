#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <bits/stdc++.h>
#include "Process.hpp"

class Scheduler
{
protected:
    //int time_quantum = -1;

public:

    virtual void addProcess(const Process& p) = 0;
    virtual int Schdule() = 0;  
    virtual bool isFinished() const = 0;
    virtual double Average_wait_time()const =0;
    virtual double Average_turnaround_time()const =0; 
    virtual int  step()const = 0;
    //virtual void set_qt(int q)=0;

    
};

#endif
