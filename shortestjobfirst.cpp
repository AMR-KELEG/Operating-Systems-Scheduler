#include "shortestjobfirst.h"

ShortestJobFirst::ShortestJobFirst(bool isPreemptive)
{
    this->isPreemptive=isPreemptive;
}

void ShortestJobFirst::addNewProcess(Process p)
{
    ReadyQueue.push_back(p);
}

Process ShortestJobFirst::getNextProcess()
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

    qSort(ReadyQueue.begin(),ReadyQueue.end(),ShortestJobFirst::compare);
    return ReadyQueue.front();
}


int ShortestJobFirst::executeCurrentProcess()
{
    if(ReadyQueue.empty())
    {
        int tempCurrentTime=currentTime;
        currentTime=FutureQueue.first().getArrivalTime();
        return FutureQueue.first().getArrivalTime()-tempCurrentTime;
    }
    if(isPreemptive)
    {
        currentTime++;
        ReadyQueue.first().setBurstTime(ReadyQueue.first().getBurstTime()-1);
        if(ReadyQueue.first().getBurstTime()==0)
            ReadyQueue.pop_front();
        return 1;
    }
    else
    {
        int currentProcessTime=ReadyQueue.front().getBurstTime();
        currentTime+=currentProcessTime;
        ReadyQueue.pop_front();
        return currentProcessTime;
    }
}

QList<Process> ShortestJobFirst::getReadyQueue()
{
    return ReadyQueue;
}

bool ShortestJobFirst::compare(Process p1, Process p2)
{
    return p1.getBurstTime()<p2.getBurstTime();
}

