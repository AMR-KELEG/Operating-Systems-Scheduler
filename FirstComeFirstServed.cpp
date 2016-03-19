#include "FirstComeFirstServed.h"

FirstComeFirstServed::FirstComeFirstServed()
{

}

void FirstComeFirstServed::addNewProcess(Process p)
{
    q.enqueue(p);
}

Process FirstComeFirstServed::getNextProcess()
{
    if(q.empty())
        return Process::GetNullProcess();
    return q.head();
}


bool FirstComeFirstServed::allProcessesDone()
{
    return q.empty();
}

void FirstComeFirstServed::InitializeScheduler(std::vector<Process> p)
{

}

int FirstComeFirstServed::executeCurrentProcess()
{
    return 0;
}
