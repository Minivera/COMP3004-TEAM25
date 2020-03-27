#include "timer.h"
#include "ui_timer.h"
#include <QTextBrowser>
#include <QTextBlock>
#include <QMessageBox>
#include <QTimer>

Timer::Timer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Timer)
{
    ui->setupUi(this);
    ui->setupUi(this);
    this->setWindowTitle("Time Form");
    timer200  =new QTimer(this);
    timer200->start(1000);

    QObject::connect(timer200, SIGNAL(timeout()), this, SLOT(A()));
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


