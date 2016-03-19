#include "simulationwindow.h"
#include "ui_simulationwindow.h"
#include <QTimer>

#include <vector>
#include <algorithm>
#include <stack>

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

SimulationWindow::SimulationWindow(std::vector<Process> vv ,int quantum,QString algo,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimulationWindow)
{
    ui->setupUi(this);

    int currentColumnCount;

    // first come first served
    std::vector<std::pair<int,int>>v; // arrival time , burst time
    std::stack<Qt::GlobalColor> colorStack;

    // some tasks
    v.push_back({2,4});
    v.push_back({1,2});
    v.push_back({1,4});
    v.push_back({1,4});
    v.push_back({1,4});

    sort(v.begin(),v.end());

    Qt::GlobalColor color;
    for (int i = 0; i < v.size(); ++i) {
        if(colorStack.empty()){
            fillStack(colorStack);
        }
        color = colorStack.top();
        colorStack.pop();

        for (int j = 0; j < v[i].second; ++j) {
            currentColumnCount = ui->tableWidget->columnCount();
            ui->tableWidget->setColumnCount(++currentColumnCount);
            ui->tableWidget->setItem(0,currentColumnCount-1 , new QTableWidgetItem);
            ui->tableWidget->item(0,currentColumnCount-1)->setBackground(color);
            ui->tableWidget->item(0,currentColumnCount-1)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(0,currentColumnCount-1)->setText(QString("%1").arg(i+1));
        }
    }

}

SimulationWindow::~SimulationWindow()
{
    delete ui;
}
