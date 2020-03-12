#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextBrowser>
#include <QTextBlock>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("DENAS PRODUCT");
    resize(700,550);
    pal.setColor(QPalette::Background, Qt::gray);
    setAutoFillBackground(true);
    setPalette(pal);

    ui->Back->resize(80,25);
    ui->Top->resize(80,25);
    ui->Down->resize(80,25);
    ui->Open->resize(80,25);
    ui->Off->resize(80,25);
    ui->Screen->resize(250,200);

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
    QApplication::instance()->exit(0);
}
