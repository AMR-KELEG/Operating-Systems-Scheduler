#ifndef FIRSTCOMEFIRSTSERVED_H
#define FIRSTCOMEFIRSTSERVED_H
#include "SchedulingAlgorithm.h"

class FirstComeFirstServed:public SchedulingAlgorithm
{
public:
    FirstComeFirstServed();
    void addNewProcess(Process p);
    Process getNextProcess();
    int executeCurrentProcess();
    QList<Process> getReadyQueue();

};

#endif // FIRSTCOMEFIRSTSERVED_H
