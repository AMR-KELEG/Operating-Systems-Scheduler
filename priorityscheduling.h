#ifndef PRIORITYSCHEDULING_H
#define PRIORITYSCHEDULING_H

#include <SchedulingAlgorithm.h>

class PriorityScheduling : public SchedulingAlgorithm
{
private:
    bool isPreemptive;
public:
    PriorityScheduling(bool isPreemptive=0);
    void addNewProcess(Process p);
    Process getNextProcess();
    int executeCurrentProcess();
    QList<Process> getReadyQueue();
    static bool compare(Process p1,Process p2);

};

#endif // PRIORITYSCHEDULING_H
