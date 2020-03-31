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
    QObject::connect(this->model, SIGNAL(valueChanged()), this, SLOT(updateRequested()));

    ui->setupUi(this);
    //Set page name
    this->setWindowTitle("DENAS PRODUCT");

    // Create all the sub widgets and link to this window.
    set = new Setting(this);
    set->hide();
    form = new Form(model, this);
    form->hide();
    timer = new Timer(model, this);
    timer->hide();

    //Set background color
    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    setMouseTracking(true);

    //hide battery level
    ui->battery->hide();
    ui->lowBatteryLabel->hide();
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

    // If the device has been booted up and everything is still hidden
    if (model->isOn() && ui->battery->isHidden()) {
        // Show everything only this time to prevent loss of focus.
        set->hide();
        form->hide();
        timer->hide();
        ui->mainView->show();
        ui->battery->show();
    } else if (!model->isOn() && !ui->battery->isHidden()) {
        // Otherwise, hide everything only once as well.
        ui->battery->hide();
        set->hide();
        form->hide();
        timer->hide();
        ui->mainView->hide();
        ui->lowBatteryLabel->hide();
        return;
    }

    // Check which menu we are at and if we should change the displays. Only display things once when the menu changes.
    currentMenu selectedMenu = model->getSelectedMenu();
    if (selectedMenu == currentMenu::Settings && set->isHidden()) {
        set->show();
        form->hide();
        timer->hide();
        ui->mainView->hide();
    } else if ((selectedMenu == currentMenu::FormPrograms || selectedMenu == currentMenu::FormFrequencies)
               && form->isHidden()) {
        set->hide();
        form->show();
        timer->hide();
        ui->mainView->hide();
    } else if ((selectedMenu == currentMenu::TimerPrograms || selectedMenu == currentMenu::TimerFrequencies)
               && timer->isHidden()) {
        set->hide();
        form->hide();
        timer->show();
        ui->mainView->hide();
    } else if ((selectedMenu == currentMenu::MainMenu || selectedMenu == currentMenu::ProgramsMenu || selectedMenu == currentMenu::FrequenciesMenu)
               && ui->mainView->isHidden()) {
        set->hide();
        form->hide();
        timer->hide();
        ui->mainView->show();
    }

    if (model->getBatteryTime() <= AppModel::lowBatteryThreshold){
       // A message when battery level is 20
        ui->lowBatteryLabel->show();

       // If we're currently running a treatment, stop
       if ((selectedMenu == currentMenu::TimerPrograms || selectedMenu == currentMenu::TimerFrequencies)) {
            model->handleMenu();
       }
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

void MainWindow::on_menuButton_clicked()
{
    // Menu button bring back the main menu and resets everything
    model->handleMenu();
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

void MainWindow::on_connectButton_clicked()
{
    model->handleElectrode();
}

void MainWindow::updateRequested() {
    update();
}
