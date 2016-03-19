#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <utility>
#include <queue>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QPushButton>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    process_grid = new QGridLayout();
    viewport = new QWidget;
    viewport->setLayout(process_grid);
    ui->process_area->setWidget(viewport);

    num_of_process = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    int arrivalTime,burstTime,priority;
    QString q=QString("p_arrival%1").arg(0);
    for(int i=0;i<num_of_process;i++)
    {
        //arrivalTime=ui->process_area->findChild();
        //burstTime=ui->process_area->findChildren(QString("p_burst%1").arg(i));
        //priority=ui->process_area->findChild(QString("p_priority%1").arg(i));
        processVector.push_back(Process(i+1));
    }

    this->hide();
    simwin = new SimulationWindow();
    simwin->show();
}

void MainWindow::on_ps_clicked()
{
    //ui->p_priority0->setDisabled(0);

}

void MainWindow::on_sjf_clicked()
{
    //ui->p_priority0->setDisabled(1);
}

void MainWindow::on_fcfs_clicked()
{
    //ui->p_priority0->setDisabled(1);
}

void MainWindow::on_rr_clicked()
{
   // ui->p_priority0->setDisabled(1);
}

void MainWindow::on_add_process_clicked()
{
    QLineEdit *arriv = new QLineEdit();
    QLineEdit *burst = new QLineEdit();
    QLineEdit *prio  = new QLineEdit();
    QPushButton *btn = new QPushButton("x");

    arriv->setObjectName(QString("p_arrival%1").arg(num_of_process));
    burst->setObjectName(QString("p_burst%1").arg(num_of_process));
    prio->setObjectName(QString("p_priority%1").arg(num_of_process));
    btn->setObjectName(QString("p_delbtn%1").arg(num_of_process));

    process_grid->addWidget(arriv,num_of_process,0);
    process_grid->addWidget(burst,num_of_process,1);
    process_grid->addWidget(prio,num_of_process,2);
    process_grid->addWidget(btn,num_of_process,3);
    num_of_process++;

}
