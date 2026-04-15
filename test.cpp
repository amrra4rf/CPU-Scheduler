#include <bits/stdc++.h>
#include "Models/Process.hpp"
#include "Algorithms/RoundRobin.hpp"

using namespace std;

int main()
{
    try
    {
        // =========================
        // Create Round Robin Scheduler
        // =========================
        RoundRobin rr(2); // time quantum = 2

        // =========================
        // Test Data
        // (pid, arrival, burst, priority)
        // =========================
        rr.addProcess(Process(1, 0, 5, 2));
        rr.addProcess(Process(2, 1, 3, 1));
        rr.addProcess(Process(3, 2, 8, 4));
        rr.addProcess(Process(4, 3, 6, 2));
        rr.addProcess(Process(5, 4, 2, 3));

        cout << "===== Round Robin Simulation =====\n\n";

        // =========================
        // Run Scheduler Step by Step
        // =========================
        int step_count = 0;
        while (!rr.isFinished())
        {
            int next_pid = rr.Schdule();

            cout << "Step " << step_count++
                 << " -> Next PID: " << next_pid << "\n";
        }

        // =========================
        // Results
        // =========================
        cout << "\n===== Results =====\n";
        cout << "Average Waiting Time: "
             << rr.Average_wait_time() << "\n";

        cout << "Average Turnaround Time: "
             << rr.Average_turnaround_time() << "\n";
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}