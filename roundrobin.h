#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H
#include "SchedulingAlgorithm.h"
class RoundRobin: public SchedulingAlgorithm
{
    int quantum;
public:
    RoundRobin(int Q=0);
    void addNewProcess(Process p);
    Process getNextProcess();
    int executeCurrentProcess();
    QList<Process> getReadyQueue();
};

#endif // ROUNDROBIN_H
