#ifndef SHORTESTJOBFIRST_H
#define SHORTESTJOBFIRST_H

#include "SchedulingAlgorithm.h"

class ShortestJobFirst : public SchedulingAlgorithm
{
private:
    bool isPreemptive;
public:
    ShortestJobFirst(bool isPreemptive=0);
    void addNewProcess(Process p);
    Process getNextProcess();
    int executeCurrentProcess();
    QList<Process> getReadyQueue();
    static bool compare(Process p1,Process p2);

};

#endif // SHORTESTJOBFIRST_H
