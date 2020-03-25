#include "timer_2.h"
#include "ui_timer_2.h"
#include <QTextBrowser>
#include <QTextBlock>
#include <QMessageBox>
#include <QTimer>

Timer_2::Timer_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Timer_2)
{
    ui->setupUi(this);
    this->setWindowTitle("Time Form");
    timer200=new QTimer(this);
    timer200->start(1000);
    //connect(ui->Back,SIGNAL(clicked(bool)),this,SLOT(on_Back_clicked()));
    QObject::connect(timer200,SIGNAL(timeout()),this,SLOT(A()));
}

Timer_2::~Timer_2()
{
    delete ui;
}



void Timer_2::A()
{

    const int R = ui->Time->text().toInt();
    ui->Time->setText(QString::number(R-1));
}
