#include "timer.h"
#include "ui_timer.h"
#include <QTextBrowser>
#include <QTextBlock>
#include <QMessageBox>
#include <QTimer>

Timer::Timer(AppModel* model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Timer)
{
    this->model = model;

    ui->setupUi(this);
    //connect
    QObject::connect(this->model, SIGNAL(valueChanged()), this, SLOT(updateRequested()));

    ui->successLabel->hide();
}

Timer::~Timer()
{
    delete ui;
}

void Timer::update() {
    ui->successLabel->hide();
    ui->timerScreen->setText(QString::number(model->getTreatmentTime()));

    if (model->getTreatmentTime() <= 0) {
        ui->successLabel->show();
    }
}

void Timer::updateRequested() {
    update();
}
