#ifndef SJF_PREEMPTIVE_HPP
#define SJF_PREEMPTIVE_HPP

#include "../Models/Scheduler.hpp"
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class sjfp : public Scheduler {
private:

    struct CompareBurst {
        bool operator()(const Process& a, const Process& b) const {
            return a.getRemaining() > b.getRemaining(); // min-heap by remaining time
        }
    };

    // All processes waiting to arrive, sorted by arrival time
    vector<Process> incoming;

    // Only processes that have arrived go here
    priority_queue<Process, vector<Process>, CompareBurst> ready_queue;

    vector<Process> finished_p;
    int time = 0;

public:
    sjfp() {
    }

    
    int step() const override
    {
        
    }
    void addProcess(const Process& p) override {
        incoming.push_back(p);
        // Keep incoming sorted by arrival time
        sort(incoming.begin(), incoming.end(), [](const Process& a, const Process& b) {
            return a.getArrival() < b.getArrival();
        });
    }

    int Schdule() override {

        // Move all processes that have arrived by current time into ready_queue
        while (!incoming.empty() && incoming.front().getArrival() <= time) {
            ready_queue.push(incoming.front());
            incoming.erase(incoming.begin());
        }

        // CPU idle — no process ready yet
        if (ready_queue.empty()) {
            time++;
            return -1;
        }

        // Pick shortest remaining time process
        Process p = ready_queue.top();
        ready_queue.pop();

        // Record start time only on first execution (must be guarded inside Process)
        p.start_p(time);

        // Execute 1 unit
        p.execute(1);



        if (!p.is_finished()) {
            ready_queue.push(p); // push back with updated remaining
        } else {
            p.finish(time + 1);  // set finish time before storing
            finished_p.push_back(p);
            cout << "PID " << p.getPID() << " FINISHED at time " << time + 1 << endl;
        }

        time++;
        return p.getPID();
    }

    bool isFinished() const override {
        return incoming.empty() && ready_queue.empty();
    }
    double Average_wait_time() const override {

        double waiting=0;
        for(Process p : finished_p){
            waiting+=p.waiting_time();
        }
        return waiting/finished_p.size();
    }
    double Average_turnaround_time() const override {
        double turn=0;
        for(Process p : finished_p ){
            turn+=p.turnarround();

        }
        return turn/finished_p.size();
    }
};

#endif