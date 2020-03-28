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
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    //Set page name
    this->setWindowTitle("Setting Form");
}

Setting::~Setting()
{
    delete ui;
}
