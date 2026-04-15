#include <bits/stdc++.h>
#include "Models/Process.hpp"
#include "utils/ProcessSorter.hpp"
#include "Algorithms/RoundRobin.hpp"

using namespace std;

int main()
{
    ProcessSorter ps;
    RoundRobin rr(2);

    // =========================
    // Add unsorted processes
    // =========================
    ps.addProcess_sorted(Process(1, 0, 5));
    ps.addProcess_sorted(Process(2, 1, 3));
    ps.addProcess_sorted(Process(3, 2, 8));
    ps.addProcess_sorted(Process(4, 3, 6));
    ps.addProcess_sorted(Process(5, 4, 2));

    cout << "===== Loading into RR =====\n";

    ps.transferToScheduler(rr);

    cout << "\n===== Round Robin Execution =====\n";

    int step = 0;
    while (!rr.isFinished())
    {
        cout << "Step " << step++
             << " PID: " << rr.Schdule() << "\n";
    }

    cout << "\n===== Results =====\n";
    cout << "Avg Waiting Time: " << rr.Average_wait_time ()<< "\n";
    cout << "Avg Turnaround Time: " << rr.Average_turnaround_time() << "\n";

    return 0;
}