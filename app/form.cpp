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

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setWindowTitle("Level Form");


}

Form::~Form()
{
    delete ui;
}


void Form::on_Menu_clicked()
{
    this->hide();


}

void Form::on_Reduce_clicked()
{

    const int R = ui->Level->text().toInt();
    ui->Level->setText(QString::number(R-1));


}


void Form::on_Add_clicked()
{


    const int R = ui->Level->text().toInt();
    ui->Level->setText(QString::number(R+1));



}

void Form::on_Enter_clicked()
{


    timer = new Timer();
    timer->show();




}

