#include <bits/stdc++.h>
#include "Models/Process.hpp"
#include "utils/ProcessSorter.hpp"

using namespace std;

int main()
{
    ProcessSorter ps;

    // =========================
    // Test Data (random arrival order)
    // =========================
    ps.addProcess_sorted(Process(1, 5, 10));
    ps.addProcess_sorted(Process(2, 1, 3));
    ps.addProcess_sorted(Process(3, 3, 7));
    ps.addProcess_sorted(Process(4, 0, 2));
    ps.addProcess_sorted(Process(5, 2, 4));

    cout << "===== ProcessSorter Output (Arrival Order) =====\n";

    // =========================
    // Expected: 4 → 2 → 5 → 3 → 1
    // =========================
    while (!ps.empty())
    {
        Process p = ps.getNext();

        cout << "PID: " << p.getPID()
             << " | Arrival: " << p.getArrival()
             << " | Burst: " << p.getBurst()
             << "\n";
    }

    return 0;
}