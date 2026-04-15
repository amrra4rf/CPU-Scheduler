#include <queue>
#include <vector>
#include <stdexcept>
#include "../Models/Process.hpp"
#include "../Models/Scheduler.hpp"

struct pcomparator
{
    bool operator()(const Process& p1, const Process& p2) const
    {
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

    void transferToScheduler(Scheduler& s, int currenttime)
    {
        while (!empty() && peek().getArrival() <= currenttime)
        {
            s.addProcess(getNext());
        }
    }
};