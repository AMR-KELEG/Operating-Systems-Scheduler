#include "simulationwindow.h"
#include "ui_simulationwindow.h"

QColor generateRandomColor(QColor mix){
    int red = rand() % 255 + 1;
    int green = rand() % 255 + 1;
    int blue = rand() % 255 + 1;

    red = (red + mix.red()) /2;
    green = (green + mix.green()) /2;
    blue = (blue + mix.blue()) /2;

    return QColor(red,green,blue);
}

SimulationWindow::SimulationWindow(QList<Process> processVector ,int quantum, std::string algo,bool preempetive,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimulationWindow)
{
    ui->setupUi(this);

    int currentColumnCount;

    for (int i = 0; i < processVector.size(); ++i) {
        processVector[i].setColor(generateRandomColor(Qt::white));
    }

    if(algo == "fcfs"){
        algorithm = new FirstComeFirstServed();
    }else if(algo == "sjf"){
        algorithm = new ShortestJobFirst(preempetive);
    }else if(algo == "ps"){
        algorithm = new PriorityScheduling(preempetive);
    }else if(algo == "rr"){
        algorithm = new RoundRobin(quantum);
    }

    algorithm->InitializeScheduler(processVector);

    while(!algorithm->allProcessesDone()) {
        Process currentProcess = algorithm->getNextProcess();
        int executionTime = algorithm->executeCurrentProcess();
        for (int j = 0; j < executionTime; ++j) {
            currentColumnCount = ui->tableWidget->columnCount();
            ui->tableWidget->setColumnCount(++currentColumnCount);
            QTableWidgetItem* currentColumn = new QTableWidgetItem;
            ui->tableWidget->setItem(0,currentColumnCount-1 , currentColumn);
            currentColumn->setBackground(currentProcess.getColor());
            currentColumn->setTextAlignment(Qt::AlignCenter);
            if(currentProcess.getColor()==Qt::white){
                currentColumn->setTextColor(Qt::white);
            }else{
                currentColumn->setTextColor(Qt::black);
            }
            currentColumn->setText(QString::number(currentProcess.getId()));
        }
    }          
    ui->time->setText(QString::number((double)algorithm->getAverageWaitingTime()));
    QStringList list;
    for(int i=0;i<currentColumnCount;i++){
        list<<QString::number(i);
    }
    ui->tableWidget->setHorizontalHeaderLabels(list);
}

SimulationWindow::~SimulationWindow()
{
    delete ui;
}
