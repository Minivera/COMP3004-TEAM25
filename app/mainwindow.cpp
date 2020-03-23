#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextBrowser>
#include <QTextBlock>
#include <QMessageBox>
#include <QTimer>

#define TIMER_TIMEOUT   (5*1000)


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
    Timer=new QTimer(this);
    Timer->start(10000);
    //connect(ui->Back,SIGNAL(clicked(bool)),this,SLOT(on_Back_clicked()));
    QObject::connect(Timer,SIGNAL(timeout()),this,SLOT(T()));
     ui->Battery->hide();



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
    ui->Battery->show();

    ui->Screen->append("ALLERGY");
    ui->Screen->append("PAIN");
    ui->Screen->append("INT.PAIN");


    //ui->Battery->setText("99");





}


void MainWindow::on_Off_clicked()
{
    ui->Screen->clear();
    ui->Battery->setText(" ");
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


void MainWindow::T()
{

    const int R = ui->Battery->text().toInt();
    ui->Battery->setText(QString::number(R-1));
}



void MainWindow::on_Top_clicked()
{
    form = new Form();
    form->show();
}


void MainWindow::on_Down_clicked()
{
    form = new Form();
    form->show();
}
