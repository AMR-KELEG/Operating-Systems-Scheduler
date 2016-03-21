#include "FirstComeFirstServed.h"
FirstComeFirstServed::FirstComeFirstServed(){

}


void FirstComeFirstServed::addNewProcess(Process p)
{
    ReadyQueue.push_back(p);
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
