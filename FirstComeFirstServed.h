#ifndef FIRSTCOMEFIRSTSERVED_H
#define FIRSTCOMEFIRSTSERVED_H
#include "SchedulingAlgorithm.h"

class FirstComeFirstServed:public SchedulingAlgorithm
{
private:
    QList<Process> ReadyQueue;
    QList<Process> FutureQueue;
    int currentTime;
public:
    FirstComeFirstServed();
    void addNewProcess(Process p);
    Process getNextProcess();
    bool allProcessesDone();
    void InitializeScheduler(QList<Process> p);
    int executeCurrentProcess();
    QList<Process> getReadyQueue();
    bool compare(Process p1,Process p2);

};

#endif // FIRSTCOMEFIRSTSERVED_H
