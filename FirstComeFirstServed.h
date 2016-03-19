#ifndef FIRSTCOMEFIRSTSERVED_H
#define FIRSTCOMEFIRSTSERVED_H
#include "SchedulingAlgorithm.h"
class FirstComeFirstServed:public SchedulingAlgorithm
{
private:
    std::list<Process> ReadyQueue;

public:
    FirstComeFirstServed();
    void addNewProcess(Process p);
    Process getNextProcess();
    bool allProcessesDone();
    void InitializeScheduler(std::vector<Process> p);
    int executeCurrentProcess();
};

#endif // FIRSTCOMEFIRSTSERVED_H
