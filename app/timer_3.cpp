#include "timer_3.h"
#include "ui_timer_3.h"
#include <QTextBrowser>
#include <QTextBlock>
#include <QMessageBox>
#include <QTimer>

Timer_3::Timer_3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Timer_3)
{
    ui->setupUi(this);
    this->setWindowTitle("Time Form");
    timer200=new QTimer(this);
    timer200->start(1000);
    //connect(ui->Back,SIGNAL(clicked(bool)),this,SLOT(on_Back_clicked()));
    QObject::connect(timer200,SIGNAL(timeout()),this,SLOT(A()));
}

Timer_3::~Timer_3()
{
    delete ui;
}

void Timer_3::A()
{

    const int R = ui->Time->text().toInt();
    ui->Time->setText(QString::number(R-1));
}
