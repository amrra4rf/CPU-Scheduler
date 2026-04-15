#ifndef SJF_HPP
#define SJF_HPP

#include "../Models/Scheduler.hpp"
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class sjf : public Scheduler {
private:
    struct CompareBurst {
        bool operator()(const Process& a, const Process& b) const {
            // TIE-BREAKER: if burst times are equal, the one that arrived FIRST gets priority
            if (a.getRemaining() == b.getRemaining()) {
                return a.getArrival() > b.getArrival(); 
            }
            // Otherwise, min-heap by remaining time
            return a.getRemaining() > b.getRemaining();
        }
    };

    vector<Process> incoming;
    priority_queue<Process, vector<Process>, CompareBurst> ready_queue;
    vector<Process> finished_p;
    
    int time = 0;
    
    // --- NEW VARIABLES FOR NON-PREEMPTIVE LOGIC ---
    bool cpu_busy = false; 
    Process active_process = Process(-1, 0, 0, 0); // Holds the process currently locked in the CPU

public:
    sjf()  {
        cout << "------------------SJF NON-PREEMPTIVE-------------------" << endl;
    }

    void addProcess(const Process& p) override {
        incoming.push_back(p);
        // Keep incoming sorted by arrival time
        sort(incoming.begin(), incoming.end(), [](const Process& a, const Process& b) {
            return a.getArrival() < b.getArrival();
        });
    }

    int Schdule() override {
        // 1. Move all arrived processes into the ready_queue
        while (!incoming.empty() && incoming.front().getArrival() <= time) {
            ready_queue.push(incoming.front());
            incoming.erase(incoming.begin());
        }

        // 2. If the CPU is free, try to pick a new process
        if (!cpu_busy) {
            if (ready_queue.empty()) {
                time++;
                return -1; // CPU is IDLE
            }
            // Pick the shortest job (or first arrived if tied)
            active_process = ready_queue.top();
            ready_queue.pop();
            
            active_process.start_p(time);
            cpu_busy = true; // Lock the CPU!
        }

        // 3. Execute the locked process for exactly 1 tick
        active_process.execute(1);
        int pid_ran = active_process.getPID();

        // 4. Check if it just finished on this tick
        if (active_process.getRemaining() == 0) {
            active_process.finish(time + 1);
            finished_p.push_back(active_process);
            
            // Unlock the CPU so a new process can be picked next second
            cpu_busy = false; 
        }

        time++;
        return pid_ran;
    }

    // Must check if the CPU is busy, otherwise the GUI might cut off the last process early
    bool isFinished() const override {
        return incoming.empty() && ready_queue.empty() && !cpu_busy;
    }

    // Required by your base Scheduler class to compile
    int step() const override {
        return time;
    }

    double Average_wait_time() const override {
        if(finished_p.empty()) return 0;
        double w = 0;
        for (Process p : finished_p) {
            w += p.waiting_time();
        }
        return w / finished_p.size();
    }

    double Average_turnaround_time() const override {
        if(finished_p.empty()) return 0;
        double turn = 0;
        for (Process p : finished_p) {
            turn += p.turnarround();
        }
        return turn / finished_p.size();
    } 
};

#endif