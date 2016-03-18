#ifndef FIRSTCOMEFIRSTSERVED_H
#define FIRSTCOMEFIRSTSERVED_H
#include "SchedulingAlgorithm.h"
#include <QQueue>
class FirstComeFirstServed:public SchedulingAlgorithm
{
private:
    QQueue<Process> q;

public:
    FirstComeFirstServed();
    void AddNewProcess(Process p);
    Process FindNextProcess();
    bool AllProcessesDone();

};

#endif // FIRSTCOMEFIRSTSERVED_H
