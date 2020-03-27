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
    QDialog(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    //Set page name
    this->setWindowTitle("Level Form");
}

Form::~Form()
{
    delete ui;
}


void Form::on_Menu_clicked()
{
    //close page
    this->hide();
}

void Form::on_Reduce_clicked()
{
    //get number and reduce it once click button
    const int R = ui->Level->text().toInt();
    ui->Level->setText(QString::number(R-1));
}

void Form::on_Add_clicked()
{
    //get number and increase it once click button
    const int R = ui->Level->text().toInt();
    ui->Level->setText(QString::number(R+1));
}

void Form::on_Enter_clicked()
{
    //go to timer page
    timer = new Timer(this);
    timer->show();
}

