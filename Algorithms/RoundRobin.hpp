# ifndef RoundRobin_HPP
#define RoundRobin_HPP

#include <bits/stdc++.h>
#include "../Models/Scheduler.hpp"
#include "../Models/Process.hpp"

class RoundRobin : public Scheduler
{
private:
    std::queue<Process> processes;
    int time_quantum=-1;
    int current_time=0;

public:
    RoundRobin(int tq) : time_quantum(tq) {}
    int set_tq(int tq){return time_quantum=tq;}
    int get_tq()const{return time_quantum;}

    void addProcess(const Process& p) override {
        if(time_quantum <=0)
            throw std::runtime_error(" Set +ve time quantum !!!!!! ");
        processes.push(p);
    }

    int Schdule() override {
        if(time_quantum <=0)
            throw std::runtime_error(" Set +ve time quantum !!!!!! ");
        if (processes.empty()) return -1;

        Process p = processes.front();
        processes.pop();

        p.start_p(current_time);

        int exec_time = std::min(time_quantum, p.getRemaining());
        p.execute(exec_time);

        current_time += exec_time;

        if (p.getRemaining() > 0) {
            processes.push(p);
        } else {
            p.finish(current_time);
        }
        return (processes.empty() ? -2 : processes.front().getPID();)
    }

    bool isFinished() const override {
        return processes.empty();
    }
};

#endif