#include "form_3.h"
#include "ui_form_3.h"
#include "mainwindow.h"
#include <QTextBrowser>
#include <QTextBlock>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#define printf qDebug
#include <stdio.h>

Form_3::Form_3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_3)
{
    ui->setupUi(this);
    this->setWindowTitle("Level Form");
}

Form_3::~Form_3()
{
    delete ui;
}

void Form_3::on_Menu_clicked()
{
    this->hide();


}

void Form_3::on_Reduce_clicked()
{

    const int R = ui->Level->text().toInt();
    ui->Level->setText(QString::number(R-1));


}


void Form_3::on_Add_clicked()
{


    const int R = ui->Level->text().toInt();
    ui->Level->setText(QString::number(R+1));



}

void Form_3::on_Enter_clicked()
{


    timer = new Timer_3();
    timer->show();




}
