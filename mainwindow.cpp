#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    process_grid = new QGridLayout();
    viewport = new QWidget;
    viewport->setLayout(process_grid);
    ui->process_area->setWidget(viewport);

    validator = new QIntValidator();
    ui->pQuanta->setValidator(validator);

    num_of_process = 0;
    MainWindow::on_fcfs_clicked();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int arrivalTime,burstTime,priority;
    quanta = ui->pQuanta->text().toInt();

    processQueue.clear();
    for(int i=0;i<num_of_process;i++)
    {
        if(isExisting[i])
        {
          arrivalTime = (ui->process_area->findChild<QLineEdit*>(QString("pArrival%1").arg(i))->text()).toInt();
          burstTime =  (ui->process_area->findChild<QLineEdit*>(QString("pBurst%1").arg(i))->text()).toInt();
          priority =  (ui->process_area->findChild<QLineEdit*>(QString("pPriority%1").arg(i))->text()).toInt();
          processQueue.push_back(Process(i+1,arrivalTime,burstTime,priority));
        }
    }

    QMessageBox msgBox;
    if(ui->pQuanta->isEnabled() &&( ui->pQuanta->text().isEmpty() || ui->pQuanta->text().toInt()<=0)){
        msgBox.setText("Please enter a valid quantum (qunatum > 0)");
        msgBox.exec();
    }else{
        simwin = new SimulationWindow(processQueue, quanta, algorithm, ui->preemptive->isChecked() );
        simwin->show();
    }
}

void MainWindow::on_ps_clicked()
{
    for(int i=0; i<num_of_process; i++)
    {
       ui->process_area->findChild<QLineEdit*>(QString("pPriority%1").arg(i))->setDisabled(0);
    }

    algorithm = "ps";
    ui->pQuanta->setDisabled(1);
    ui->preemptive->setEnabled(1);

}

void MainWindow::on_sjf_clicked()
{
    for(int i=0; i<num_of_process; i++)
    {
       ui->process_area->findChild<QLineEdit*>(QString("pPriority%1").arg(i))->setDisabled(1);
    }

    algorithm = "sjf";
    ui->pQuanta->setDisabled(1);
    ui->preemptive->setEnabled(1);
}

void MainWindow::on_fcfs_clicked()
{
    for(int i=0; i<num_of_process; i++)
    {
       ui->process_area->findChild<QLineEdit*>(QString("pPriority%1").arg(i))->setDisabled(1);
    }

    algorithm = "fcfs";
    ui->pQuanta->setDisabled(1);
    ui->preemptive->setDisabled(1);

}

void MainWindow::on_rr_clicked()
{
    for(int i=0; i<num_of_process; i++)
    {
       ui->process_area->findChild<QLineEdit*>(QString("pPriority%1").arg(i))->setDisabled(1);
    }

    algorithm = "rr";
    ui->pQuanta->setEnabled(1);
    ui->preemptive->setDisabled(1);

}

void MainWindow::on_add_process_clicked()
{
    QLineEdit *arriv = new QLineEdit();
    QLineEdit *burst = new QLineEdit();
    QLineEdit *prio  = new QLineEdit();
    QPushButton *btn = new QPushButton("x");
    connect(btn,SIGNAL(clicked()),this,SLOT(del_row()));

    arriv->setObjectName(QString("pArrival%1").arg(num_of_process));
    burst->setObjectName(QString("pBurst%1").arg(num_of_process));
    prio->setObjectName(QString("pPriority%1").arg(num_of_process));
    btn->setObjectName(QString("pDelbtn%1").arg(num_of_process));

    if(algorithm == "sjf" || algorithm == "fcfs" || algorithm == "rr") prio->setDisabled(1);

    process_grid->addWidget(arriv,num_of_process,0);
    process_grid->addWidget(burst,num_of_process,1);
    process_grid->addWidget(prio,num_of_process,2);
    process_grid->addWidget(btn,num_of_process,3);
    num_of_process++;
    isExisting.push_back(1);
}


void MainWindow::del_row()
{
    QPushButton * senderButton = qobject_cast<QPushButton *>(this->sender());
    QString btnId= senderButton->objectName().split("pDelbtn")[1];
    removeRow(process_grid,btnId.toInt(),1);
    isExisting[btnId.toInt()]=0;
}


void MainWindow::remove(QGridLayout *layout, int row, int column, bool deleteWidgets) {
    for (int i = layout->count() - 1; i >= 0; i--) {
        int r, c, rs, cs;
        layout->getItemPosition(i, &r, &c, &rs, &cs);
        if ((r <= row && r + rs - 1 >= row) || (c <= column && c + cs - 1 >= column)) {
            QLayoutItem *item = layout->takeAt(i);
            if (deleteWidgets) {
                deleteChildWidgets(item);
            }
            delete item;
        }
    }
}


void MainWindow::deleteChildWidgets(QLayoutItem *item) {
    if (item->layout()) {
        for (int i = 0; i < item->layout()->count(); i++) {
            deleteChildWidgets(item->layout()->itemAt(i));
        }
    }
    delete item->widget();
}


void MainWindow::removeRow(QGridLayout *layout, int row, bool deleteWidgets) {
    remove(layout, row, -1, deleteWidgets);
    layout->setRowMinimumHeight(row, 0);
    layout->setRowStretch(row, 0);
}
