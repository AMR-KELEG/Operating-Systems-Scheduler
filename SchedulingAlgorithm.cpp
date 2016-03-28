#include "SchedulingAlgorithm.h"


long double SchedulingAlgorithm::getAverageWaitingTime() const
{
    return 1.0*totalWaitingTime/numberOfProcesses;
}

void SchedulingAlgorithm::InitializeScheduler(QList<Process> p)
{
    FutureQueue =p;
    qSort(FutureQueue.begin(),FutureQueue.end(),Process::isLess);
    currentTime=0;
    totalWaitingTime=0;
    numberOfProcesses=p.size();
}

bool SchedulingAlgorithm::allProcessesDone()
{
    return ReadyQueue.empty() && FutureQueue.empty();
}

