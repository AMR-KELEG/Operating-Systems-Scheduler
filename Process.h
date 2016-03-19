#ifndef PROCESS_H
#define PROCESS_H
#include <QMainWindow>
class Process{
    private:
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    Qt::GlobalColor color;


    //id
    //QtColor

    public:
    static Process GetNullProcess();

    Process(int id=-1,int a=0,int b=0,int p=0);
    int getPriority() const;
    void setPriority(int value);
    int getBurstTime() const;
    void setBurstTime(int value);
    int getArrivalTime() const;
    void setArrivalTime(int value);
};

#endif // PROCESS_H
