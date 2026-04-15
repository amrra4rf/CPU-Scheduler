#ifndef PROCESS_SORTER_HPP
#define PROCESS_SORTER_HPP

#include <queue>
#include <vector>
#include <stdexcept>
#include "../Models/Process.hpp"
#include "../Models/Scheduler.hpp"

struct pcomparator
{
    bool operator()(const Process& p1, const Process& p2) const
    {
        // min-heap by arrival time
        return p1.getArrival() > p2.getArrival();
    }
};

class ProcessSorter
{
private:
    std::priority_queue<
        Process,
        std::vector<Process>,
        pcomparator
    > pq;

public:
    void addProcess_sorted(const Process& p)
    {
        pq.push(p);
    }

    bool empty() const
    {
        return pq.empty();
    }

    Process getNext()
    {
        if (pq.empty())
            throw std::runtime_error("ProcessSorter is empty");

        Process top = pq.top();
        pq.pop();
        return top;
    }

    Process peek() const
    {
        if (pq.empty())
            throw std::runtime_error("ProcessSorter is empty");

        return pq.top();
    }

    void transferToScheduler(Scheduler& s)
    {
        while (!pq.empty())
        {
            s.addProcess(pq.top());
            pq.pop();
        }
    }
};

#endif 