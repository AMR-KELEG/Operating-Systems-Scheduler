#include "FirstComeFirstServed.h"
FirstComeFirstServed::FirstComeFirstServed(){}

void FirstComeFirstServed::InitializeScheduler(std::vector<Process> p)
{
    for(unsigned int i=0;i<p.size();i++)
        addNewProcess(p[i]);
    qSort(ReadyQueue.begin(),ReadyQueue.end(),Process::isLess);
}

void FirstComeFirstServed::addNewProcess(Process p)
{
    ReadyQueue.push_back(p);
}


bool FirstComeFirstServed::allProcessesDone()
{
    return ReadyQueue.empty();
}

Process FirstComeFirstServed::getNextProcess()
{
    if(ReadyQueue.empty())
        return Process::GetNullProcess();
    return ReadyQueue.front();
}


int FirstComeFirstServed::executeCurrentProcess()
{
    if(allProcessesDone())
        return -1;
    Process currentProcess=ReadyQueue.front();
    ReadyQueue.pop_front();
    return currentProcess.getBurstTime();
}
