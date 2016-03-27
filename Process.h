#ifndef PROCESS_H
#define PROCESS_H

#include <QMainWindow>

class Process{
private:
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    QColor color;
    //static Process * NULLPROCESS;
public:
    static Process GetNullProcess();
    static bool isLess(Process p1,Process p2);
    Process(int id=0,int a=0,int b=0,int p=0, Qt::GlobalColor color = Qt::white);
    int getPriority() const;
    void setPriority(int value);
    int getBurstTime() const;
    void setBurstTime(int value);
    int getArrivalTime() const;
    void setArrivalTime(int value);    
    int getId() const;
    void setId(int value);
    QColor getColor();
    void setColor(QColor value);

};

#endif // PROCESS_H
