#ifndef PRIORITY_NONP_HPP
#define PRIORITY_NONP_HPP

#include <bits/stdc++.h>
#include <vector>
#include "../Models/Scheduler.hpp"
#include "../Models/Process.hpp"
#include "../utils/PrioretySorter.hpp" 

class Priority_NonP : public Scheduler
{
private:
    PrioritySorter readyP;
    std::vector<Process> finished;
    int current_time = 0;
    
    // Fix: Initialize with dummy values to avoid default constructor error
    Process current_process = Process(-1, 0, 0, 0); 
    bool hasCurrent = false;

public:
    Priority_NonP() {
        std::cout << "------------------PRIORITY NON-PREEMPTIVE-------------------" << std::endl;
    }

    void addProcess(const Process& p) override
    {
        this->readyP.addProcess_sorted_priority(p);
    }

    int step() const override {
        return current_time; 
    }

    int Schdule() override
    {
        // 1. If CPU is free, try to load a new process
        if (!hasCurrent)
        {
            if (readyP.empty()) {
                current_time++;
                return -1; // CPU is idle
            }

            current_process = readyP.getNextProcess();

            if (current_time < current_process.getArrival())
                current_time = current_process.getArrival();

            current_process.start_p(current_time);
            hasCurrent = true;
        }

        // 2. Execute the locked process for exactly 1 tick
        current_process.execute(1);
        int active_pid = current_process.getPID();

        // 3. Check if it finished on this tick
        if (current_process.getRemaining() == 0)
        {
            current_process.finish(current_time + 1); // Mark finish time for the math
            finished.push_back(current_process);
            hasCurrent = false; // Unlock CPU
        }

        current_time++;
        return active_pid;
    }

    bool isFinished() const override
    {
        // Fix: Must make sure CPU is also unlocked, otherwise it cuts off early
        return readyP.empty() && !hasCurrent;
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