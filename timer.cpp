#include "timer.h"
#include "ui_timer.h"
#include <QTextBrowser>
#include <QTextBlock>
#include <QMessageBox>
#include <QTimer>

Timer::Timer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Timer)
{
    ui->setupUi(this);
    ui->setupUi(this);
    this->setWindowTitle("Time Form");
    timer200=new QTimer(this);
    timer200->start(1000);
    //connect(ui->Back,SIGNAL(clicked(bool)),this,SLOT(on_Back_clicked()));
    QObject::connect(timer200,SIGNAL(timeout()),this,SLOT(A()));


}

Timer::~Timer()
{
    delete ui;
}


void Timer::A()
{

    const int R = ui->Time->text().toInt();
    ui->Time->setText(QString::number(R+1));
}


