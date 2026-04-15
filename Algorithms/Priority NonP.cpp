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
        if (readyP.empty())
            return -1;

        Process p = readyP.getNextProcess();


        if (current_time < p.getArrival())
            current_time = p.getArrival();

        p.start_p(current_time);

        current_time += p.getBurst();
        p.finish(current_time);

        finished.push_back(p);

        return p.getPID();
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