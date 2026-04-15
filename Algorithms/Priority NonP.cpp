#ifndef PRIORITY_NONP_HPP
#define PRIORITY_NONP_HPP

#include <bits/stdc++.h>
#include "../Models/Scheduler.hpp"
#include "../Models/Process.hpp"
#include "../utils/PrioretySorter.hpp"

class Priority_NonP : public Scheduler
{
private:
    PrioritySorter readyP;
    std::vector<Process> finished;
    int current_time = 0;
    Process current_process;
    bool hasCurrent = false;

public:
    void addProcess(const Process& p) override
    {
        this->readyP.addProcess_sorted_priority(p);
    }

    int step(){
        if(readyP.empty())
            return -1;
        readyP.peek().getPID();

    }

    int schedule() override
{

    if (!hasCurrent)
    {
        if (readyP.empty())
            return -1;

        current_process = readyP.getNextProcess();

        if (current_time < current_process.getArrival())
            current_time = current_process.getArrival();

        current_process.start_p(current_time);
        hasCurrent = true;
    }

    current_process.execute(1);
    current_time++;


    if (current_process.getRemaining() == 0)
    {
        current_process.finish(current_time);
        finished.push_back(current_process);
        hasCurrent = false;
    }

    return current_process.getPID();
}

    bool isFinished() const override
    {
        return readyP.empty();
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