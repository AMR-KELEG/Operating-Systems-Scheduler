#ifndef FIRSTCOMEFIRSTSERVED_H
#define FIRSTCOMEFIRSTSERVED_H
#include "SchedulingAlgorithm.h"
#include <QtAlgorithms>
class FirstComeFirstServed:public SchedulingAlgorithm
{
private:
    QList<Process> ReadyQueue;

public:
    FirstComeFirstServed();
    void addNewProcess(Process p);
    Process getNextProcess();
    bool allProcessesDone();
    void InitializeScheduler(std::vector<Process> p);
    int executeCurrentProcess();
};

#endif // FIRSTCOMEFIRSTSERVED_H
