#include "FirstComeFirstServed.h"
FirstComeFirstServed::FirstComeFirstServed(){}

void FirstComeFirstServed::InitializeScheduler(QList<Process> p)
{
    FutureQueue =p;
    currentTime=0;
    qSort(FutureQueue.begin(),FutureQueue.end(),Process::isLess);
}

void FirstComeFirstServed::addNewProcess(Process p)
{
    ReadyQueue.push_back(p);
}


bool FirstComeFirstServed::allProcessesDone()
{
    return ReadyQueue.empty() && FutureQueue.empty();
}

Process FirstComeFirstServed::getNextProcess()
{
    while(!FutureQueue.empty() && FutureQueue.first().getArrivalTime()<=currentTime)
    {
        ReadyQueue.push_back(FutureQueue.first());
        FutureQueue.pop_front();
    }

    if(ReadyQueue.empty())
    {
        //Return NULL PROCESS
        return Process();

    }
    return ReadyQueue.front();
}


int FirstComeFirstServed::executeCurrentProcess()
{
    if(ReadyQueue.empty())
    {
        int tempCurrentTime=currentTime;
        currentTime=FutureQueue.first().getArrivalTime();
        return FutureQueue.first().getArrivalTime()-tempCurrentTime;
    }
    int currentProcessTime=ReadyQueue.front().getBurstTime();
    currentTime+=currentProcessTime;
    ReadyQueue.pop_front();
    return currentProcessTime;
}

QList<Process> FirstComeFirstServed::getReadyQueue()
{
    return ReadyQueue;
}

bool FirstComeFirstServed::compare(Process p1, Process p2)
{
    return 1;
}
