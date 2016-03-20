#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QMainWindow>
#include <vector>
#include <algorithm>
#include <stack>

#include "Process.h"
#include "SchedulingAlgorithm.h"
#include "FirstComeFirstServed.h"

namespace Ui {
class SimulationWindow;
}

class SimulationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimulationWindow(std::vector<Process> processVector =std::vector<Process>(),int quantum=0, std::string algo="0", QWidget *parent = 0);
    SchedulingAlgorithm * algorithm;
    ~SimulationWindow();

private:
    Ui::SimulationWindow *ui;
};

#endif // SIMULATIONWINDOW_H
