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
    void addNewProcess(Process p);
    Process getNextProcess();
    bool allProcessesDone();
    void InitializeScheduler(std::vector<Process> p);
    int executeCurrentProcess();
    void ChangeAlgorithm(SchedulingAlgorithm * sa);

};

#endif // FIRSTCOMEFIRSTSERVED_H
