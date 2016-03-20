#include "simulationwindow.h"
#include "ui_simulationwindow.h"



void fillStack(std::stack<Qt::GlobalColor> &colorStack){
    colorStack.push(Qt::darkYellow);
    colorStack.push(Qt::darkMagenta);
    colorStack.push(Qt::darkBlue);
    colorStack.push(Qt::green);
    colorStack.push(Qt::lightGray);
    colorStack.push(Qt::darkGray);
    colorStack.push(Qt::black);
    colorStack.push(Qt::darkRed);
    colorStack.push(Qt::red);
    colorStack.push(Qt::darkCyan);
    colorStack.push(Qt::blue);
    colorStack.push(Qt::gray);
    colorStack.push(Qt::cyan);
    colorStack.push(Qt::yellow);
    colorStack.push(Qt::magenta);
    colorStack.push(Qt::darkGreen);
}

SimulationWindow::SimulationWindow(std::vector<Process> processVector ,int quantum, std::string algo,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimulationWindow)
{
    ui->setupUi(this);

    int currentColumnCount;    
    std::stack<Qt::GlobalColor> colorStack;

    // assign color to each process
    for (int i = 0; i < processVector.size(); ++i) {
        if(colorStack.empty()){
            fillStack(colorStack);
        }
        processVector[i].setColor(colorStack.top());
        colorStack.pop();
    }

    if(algo == "fcfs"){
        algorithm = new FirstComeFirstServed();
    }else if(algo == "sjf"){

    }else if(algo == "ps"){

    }else if(algo == "rr"){

    }

    algorithm->InitializeScheduler(processVector);

    while(!algorithm->allProcessesDone()) {
        Process temp = algorithm->getNextProcess();
        int executionTime = algorithm->executeCurrentProcess();
        for (int j = 0; j < executionTime; ++j) {
            currentColumnCount = ui->tableWidget->columnCount();
            ui->tableWidget->setColumnCount(++currentColumnCount);
            ui->tableWidget->setItem(0,currentColumnCount-1 , new QTableWidgetItem);
            ui->tableWidget->item(0,currentColumnCount-1)->setBackground(temp.getColor());
            ui->tableWidget->item(0,currentColumnCount-1)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(0,currentColumnCount-1)->setTextColor(Qt::black);
            ui->tableWidget->item(0,currentColumnCount-1)->setText(QString("%1").arg(temp.getId()));
        }
    }
}

SimulationWindow::~SimulationWindow()
{
    delete ui;
}
