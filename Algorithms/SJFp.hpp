#ifndef SJFP_HPP
#define SJFP_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "../Models/Scheduler.hpp"
#include "../Models/Process.hpp"

using namespace std;

class sjfp : public Scheduler {
private:
    // This sorts the priority_queue automatically by Shortest Remaining Time
    struct CompareRemaining {
        bool operator()(const Process& a, const Process& b) const {
            // TIE-BREAKER: If remaining times are exactly the same, use First-Come-First-Serve
            if (a.getRemaining() == b.getRemaining()) {
                return a.getArrival() > b.getArrival(); 
            }
            // Primary sort: Lowest remaining time floats to the top
            return a.getRemaining() > b.getRemaining(); 
        }
    };

    vector<Process> incoming;
    priority_queue<Process, vector<Process>, CompareRemaining> ready_queue;
    vector<Process> finished_p;
    int time = 0;

public:
    sjfp() {
        cout << "------------------SJF PREEMPTIVE-------------------" << endl;
    }

    void addProcess(const Process& p) override {
        incoming.push_back(p);
        // Keep incoming sorted by arrival time
        sort(incoming.begin(), incoming.end(), [](const Process& a, const Process& b) {
            return a.getArrival() < b.getArrival();
        });
    }

    int Schdule() override {
        // 1. Move all processes that have arrived by current time into ready_queue
        while (!incoming.empty() && incoming.front().getArrival() <= time) {
            ready_queue.push(incoming.front());
            incoming.erase(incoming.begin());
        }

        // 2. CPU idle — no process ready yet
        if (ready_queue.empty()) {
            time++;
            return -1; // -1 tells your GUI to draw the grey "Idle" block
        }

        // 3. Pick the process with the shortest remaining time. 
        Process p = ready_queue.top();
        ready_queue.pop();

        // Record start time (your Process class safely ignores this if it already started)
        p.start_p(time);

        // Execute for exactly 1 tick
        p.execute(1);
        int active_pid = p.getPID();

        // 4. Check if it just finished
        if (p.getRemaining() == 0) {
            p.finish(time + 1);
            finished_p.push_back(p); // SAVE IT FOR THE MATH!
        } else {
            // PREEMPTION MAGIC: It's not done, so push it back!
            // If a shorter process arrives next tick, the queue will put the new one on top.
            ready_queue.push(p); 
        }

        time++;
        return active_pid;
    }

    bool isFinished() const override {
        return incoming.empty() && ready_queue.empty();
    }

    int step() const override {
        return time;
    }

    double Average_wait_time() const override {
        if (finished_p.empty()) return 0;
        double w = 0;
        for (Process p : finished_p) {
            w += p.waiting_time();
        }
        return w / finished_p.size();
    }

    double Average_turnaround_time() const override {
        if (finished_p.empty()) return 0;
        double turn = 0;
        for (Process p : finished_p) {
            turn += p.turnarround();
        }
        return turn / finished_p.size();
    }
};

#endif