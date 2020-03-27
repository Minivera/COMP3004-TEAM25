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
    this->setWindowTitle("DENAS PRODUCT");

    set = new Setting(this);
    set->hide();
    form = new Form(model, this);
    form->hide();
    timer = new Timer(model, this);
    timer->hide();

    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    setMouseTracking(true);

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
    model->handleBack();
}

void MainWindow::on_Update_requested() {
    update();
}

void MainWindow::on_upButton_clicked()
{
    model->handleTop();
}

void MainWindow::on_bottomButton_clicked()
{
    model->handleBottom();
}

void MainWindow::on_enterButton_clicked()
{
    model->handleEnter();
}

void MainWindow::on_leftButton_clicked()
{
    model->handleLeft();
}

void MainWindow::on_rightButton_clicked()
{
    model->handleRight();
}
