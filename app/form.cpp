#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"
#include <QTextBrowser>
#include <QTextBlock>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#define printf qDebug
#include <stdio.h>

Form::Form(AppModel* model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    this->model = model;

    ui->setupUi(this);
    QObject::connect(this->model, SIGNAL(valueChanged()), this, SLOT(updateRequested()));
}

Form::~Form()
{
    delete ui;
}

void Form::update() {
    ui->Level->setText(QString::number(model->getFrequency()));
}

void Form::updateRequested() {
    update();
}
