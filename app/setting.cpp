#include "setting.h"
#include "ui_setting.h"
#include <QTextBrowser>
#include <QTextBlock>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#define printf qDebug
#include <stdio.h>

Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    this->setWindowTitle("Setting Form");

}

Setting::~Setting()
{
    delete ui;
}



void Setting::on_Back_clicked()
{
    this->hide();


}

void Setting::on_Reduce_clicked()
{

    const int R = ui->Volice->text().toInt();
    ui->Volice->setText(QString::number(R-1));


}


void Setting::on_Add_clicked()
{


    const int R = ui->Volice->text().toInt();
    ui->Volice->setText(QString::number(R+1));



}



void Setting::on_Decrease_clicked()
{

    const int R = ui->Light->text().toInt();
    ui->Light->setText(QString::number(R-1));


}


void Setting::on_Increase_clicked()
{


    const int R = ui->Light->text().toInt();
    ui->Light->setText(QString::number(R+1));



}
