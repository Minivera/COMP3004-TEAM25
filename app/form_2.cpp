#include "form_2.h"
#include "ui_form_2.h"
#include "mainwindow.h"
#include <QTextBrowser>
#include <QTextBlock>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#define printf qDebug
#include <stdio.h>

Form_2::Form_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_2)
{
    ui->setupUi(this);
    this->setWindowTitle("Level Form");

}

Form_2::~Form_2()
{
    delete ui;
}

void Form_2::on_Menu_clicked()
{
    this->hide();


}

void Form_2::on_Reduce_clicked()
{

    const int R = ui->Level->text().toInt();
    ui->Level->setText(QString::number(R-1));


}


void Form_2::on_Add_clicked()
{


    const int R = ui->Level->text().toInt();
    ui->Level->setText(QString::number(R+1));



}

void Form_2::on_Enter_clicked()
{


    timer = new Timer_2();
    timer->show();




}
