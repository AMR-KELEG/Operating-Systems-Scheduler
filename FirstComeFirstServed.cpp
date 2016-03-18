#include "FirstComeFirstServed.h"

FirstComeFirstServed::FirstComeFirstServed()
{

}

void FirstComeFirstServed::AddNewProcess(Process p)
{
    q.enqueue(p);
}

Process FirstComeFirstServed::FindNextProcess()
{
    if(q.empty())
        return Process::GetNullProcess();
    return q.head();
}


bool FirstComeFirstServed::AllProcessesDone()
{
    return q.empty();
}
