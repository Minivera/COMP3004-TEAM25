#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextBrowser>
#include <QTextBlock>
#include <QMessageBox>
#include <QTimer>

#define TIMER_TIMEOUT   (5*1000)


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("DENAS PRODUCT");
    //set page color
    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    setMouseTracking(true);
    //Seting speed
    Timer=new QTimer(this);
    Timer->start(10000);
    //connect(ui->Back,SIGNAL(clicked(bool)),this,SLOT(on_Back_clicked()));
    //connect battery
    QObject::connect(Timer,SIGNAL(timeout()),this,SLOT(T()));
    ui->Battery->hide();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Open_clicked()
{
    //Open screen
    if (ui->Screen->document()->blockCount() > 100)
    {
        ui->Screen->clear();
    }
    ui->Screen->document()->setMaximumBlockCount(100);
    ui->Battery->show();

    ui->Screen->append("ALLERGY");
    ui->Screen->append("PAIN");
    ui->Screen->append("INT.PAIN");


    //ui->Battery->setText("99");





}


void MainWindow::on_Off_clicked()
{
    //close screen
    ui->Screen->clear();
    ui->Battery->hide();
    //QApplication* e;
     //e->exit(0);


}

void MainWindow::on_Back_clicked()
{
    //go to power level page
    form = new Form(this);
    form->show();
}

void MainWindow::on_Set_clicked()
{
    //go to setting page
    set = new Setting(this);
    set->show();
}


void MainWindow::T()
{
    //Set battery number
    const int R = ui->Battery->text().toInt();
    ui->Battery->setText(QString::number(R-1));
}



void MainWindow::on_Top_clicked()
{
    //go to power level page
    form_2 = new Form_2(this);
    form_2->show();

}


void MainWindow::on_Down_clicked()
{
    //go to power level page
    form_3 = new Form_3(this);
    form_3->show();

}
