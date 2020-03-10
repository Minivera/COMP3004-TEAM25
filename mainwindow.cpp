#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextBrowser>
#include <QTextBlock>
#include <QMessageBox>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("DENAS PRODUCT");

    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    setMouseTracking(true);


    //connect(ui->Back,SIGNAL(clicked(bool)),this,SLOT(on_Back_clicked()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Open_clicked()
{
    if (ui->Screen->document()->blockCount() > 100)
    {
        ui->Screen->clear();
    }
    ui->Screen->document()->setMaximumBlockCount(100);
    ui->Screen->append("Use Case1");
    ui->Screen->append("Use Case2");
    ui->Screen->append("Use Case3");
    ui->Screen->append("Use Case4");
    ui->Screen->append("Use Case5");
    ui->Screen->append("Use Case6");


}


void MainWindow::on_Off_clicked()
{
    ui->Screen->clear();
    //QApplication* e;
     //e->exit(0);


}

void MainWindow::on_Back_clicked()
{
    form = new Form();
    form->show();
}

void MainWindow::on_Set_clicked()
{
    set = new Setting();
    set->show();
}



