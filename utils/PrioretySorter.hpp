#ifndef PRIORITY_SORTER_HPP
#define PRIORITY_SORTER_HPP

#include <queue>
#include <vector>
#include <stdexcept>
#include "../Models/Process.hpp"

struct PriorityCmp
{
    bool operator()(const Process& p1, const Process& p2) const
    {
        // smaller priority number = higher priority
        return p1.getPriority() > p2.getPriority();
    }
};

class PrioritySorter
{
private:
    std::priority_queue<
        Process,
        std::vector<Process>,
        PriorityCmp
    > pq;

public:
    void addProcess_sorted_priority(const Process& p)
    {
        pq.push(p);
    }

    bool empty() const
    {
        return pq.empty();
    }

    Process getNextProcess()
    {
        if (pq.empty())
            throw std::runtime_error("Queue is empty");

        Process top = pq.top();
        pq.pop();
        return top;
    }

    Process peek() const
    {
        if (pq.empty())
            throw std::runtime_error("Queue is empty");

        return pq.top();
    }
};

#endif