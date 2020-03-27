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
    QObject::connect(this->model, SIGNAL(valueChanged()), this, SLOT(on_Update_requested()));
}

Timer::~Timer()
{
    delete ui;
}

void Timer::update() {
    ui->timerScreen->setText(QString::number(model->getTreatmentTime()));
}

void Timer::on_Update_requested() {
    update();
}
