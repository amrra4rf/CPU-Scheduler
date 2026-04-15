#ifndef ROUNDROBIN_HPP
#define ROUNDROBIN_HPP

#include <bits/stdc++.h>
#include "../Models/Scheduler.hpp"
#include "../Models/Process.hpp"

class RoundRobin : public Scheduler
{
private:
    std::queue<Process> processes;
    std::vector<Process> finished;
    int time_quantum;
    int current_time = 0;
    int total_processes = 0;

public:
    RoundRobin(int tq)
    {
        if (tq <= 0)
            throw std::runtime_error("Time quantum must be positive");
        time_quantum = tq;
    }

    int set_tq(int tq)
    {
        if (tq <= 0)
            throw std::runtime_error("Time quantum must be positive");
        return time_quantum = tq;
    }

    int get_tq() const { return time_quantum; }

    void addProcess(const Process& p) override
    {
        processes.push(p);
        total_processes++;
    }

    int Schdule() override
    {
        if (processes.empty()) return -1;

        Process p = processes.front();
        processes.pop();

        p.start_p(current_time);

        int exec_time = std::min(time_quantum, p.getRemaining());
        p.execute(exec_time);

        current_time += exec_time;

        if (p.getRemaining() > 0)
        {
            processes.push(p);
        }
        else
        {
            p.finish(current_time);
            finished.push_back(p);
        }

        return p.getPID();
    }
    int step()const override{
        if (processes.empty()) return -1;
        return processes.front().getPID();
        
    }

    bool isFinished() const override
    {
        return processes.empty();
    }

    double Average_wait_time() const override
    {
        if (finished.empty()) return 0;

        double sum = 0;
        for (const auto& p : finished)
            sum += p.waiting_time();

        return sum / finished.size();
    }

    double Average_turnaround_time() const override
    {
        if (finished.empty()) return 0;

        double sum = 0;
        for (const auto& p : finished)
            sum += p.turnarround();

        return sum / finished.size();
    }
};

#endif
