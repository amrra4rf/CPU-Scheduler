#ifndef PROCESS_H
#define PROCESS_H
#pragma once
#include <bits/stdc++.h>
#include <algorithm>


class Process
{
private:
    int pid ;
    int burst_time;
    int arrival_time;
    int priority;
    int start_time=-1;
    int finish_time;
    int remaining_time;
    bool started=false;

public:
   Process(int id, int at, int bt, int pr = 0)
    {
        pid = id;
        arrival_time = at;
        burst_time = bt;
        remaining_time = bt;
        priority = pr;
    }


    //added by walid

    bool is_finished(){
        return remaining_time<=0;
    }
    int start_p(int t){
        if(start_time ==-1)
            start_time = t;
        return start_time;
    }

    int execute(int q_time){
        remaining_time-=q_time;
        return std::max(remaining_time,0);
    }
    int finish(int f_time){
        return finish_time=f_time;
    }
    int turnarround()const {
        return finish_time-arrival_time;
    }
    int waiting_time()const{
        return turnarround()-burst_time;
    }


    int getRemaining() const { return remaining_time; }
    int getArrival() const { return arrival_time; }
    int getBurst() const { return burst_time; }
    int getPriority() const { return priority; }
    int getFinish() const { return finish_time; }
    int getStart() const { return start_time; }
    int getPID() const { return pid; }

};

#endif