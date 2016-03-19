#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QMainWindow>
#include "SchedulingAlgorithm.h"
#include <vector>
namespace Ui {
class SimulationWindow;
}

class SimulationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimulationWindow(std::vector<Process> vv =std::vector<Process>(),int quantum=0,QString algo="0",QWidget *parent = 0);
    SchedulingAlgorithm * sa;
    ~SimulationWindow();

private:
    Ui::SimulationWindow *ui;
};

#endif // SIMULATIONWINDOW_H
