#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextBrowser>
#include <QTextBlock>
#include <QMessageBox>
#include <QTimer>

#define TIMER_TIMEOUT   (5*1000)


MainWindow::MainWindow(AppModel* model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->model = model;
    QObject::connect(this->model, SIGNAL(valueChanged()), this, SLOT(on_Update_requested()));

    ui->setupUi(this);
    //Set page name
    this->setWindowTitle("DENAS PRODUCT");

    set = new Setting(this);
    set->hide();
    form = new Form(model, this);
    form->hide();
    timer = new Timer(model, this);
    timer->hide();
 readme-and-comment-work
    //Set background color
    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    setMouseTracking(true);
 readme-and-comment-work
    //hide battery level
    ui->battery->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete set;
    delete form;
    delete timer;
}

void MainWindow::update() {
    ui->battery->setText(QString::number(model->getBatteryTime()));
    if (model->isOn()) {
        set->hide();
        form->hide();
        timer->hide();
        ui->mainView->show();
        ui->battery->show();
    } else {
        ui->battery->hide();
        set->hide();
        form->hide();
        timer->hide();
        ui->mainView->hide();
        return;
    }

    if (model->getSelectedMenu() == currentMenu::Settings) {
        set->show();
        form->hide();
        timer->hide();
        ui->mainView->hide();
    } else if (model->getSelectedMenu() == currentMenu::Form) {
        set->hide();
        form->show();
        timer->hide();
        ui->mainView->hide();
    } else if (model->getSelectedMenu() == currentMenu::Timer) {
        set->hide();
        form->hide();
        timer->show();
        ui->mainView->hide();
    } else {
        set->hide();
        form->hide();
        timer->hide();
        ui->mainView->show();
    }

    ui->mainView->setModel(model->getListViewMenuModel());
    ui->mainView->setCurrentIndex(model->getSelectedItem());
}

void MainWindow::on_onButton_clicked()
{
    model->isOn() ? model->powerOff() : model->powerOn();
}

void MainWindow::on_backButton_clicked()
{

    //Set back button to back to menu
    model->handleBack();
}

void MainWindow::on_Update_requested() {
    update();
}

void MainWindow::on_upButton_clicked()
{

     //set up direction

    model->handleTop();
}

void MainWindow::on_bottomButton_clicked()
{

     //set down direction

    model->handleBottom();
}

void MainWindow::on_enterButton_clicked()
{

    //Set enter button to go to power level page

    model->handleEnter();
}

void MainWindow::on_leftButton_clicked()
{

     //set left direction

    model->handleLeft();
}

void MainWindow::on_rightButton_clicked()
{

    //set right direction

    model->handleRight();
}
