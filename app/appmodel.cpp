#include "appmodel.h"

AppModel::AppModel(QObject *parent) : QObject(parent)
{
    menuModel = new QStringListModel();

    batteryTimer = new QTimer();
    treatmentTimer = new QTimer();

    QObject::connect(batteryTimer, SIGNAL(timeout()), this, SLOT(Timer_changed()));
    QObject::connect(treatmentTimer, SIGNAL(timeout()), this, SLOT(TreatmentTimer_changed()));
}

AppModel::~AppModel() {
    delete menuModel;
    delete batteryTimer;
    delete treatmentTimer;
}

void AppModel::powerOn() {
    on = true;
    batteryTimer->start(1000);

    QStringList list;
    list << "PROGRAMS" << "SETTINGS";
    menuModel->setStringList(list);

    emit valueChanged();
}

void AppModel::powerOff() {
    on = false;
    batteryTimer->stop();

    QStringList list;
    menuModel->setStringList(list);

    emit valueChanged();
}

void AppModel::handleBack() {
    if (selectedMenu == currentMenu::Settings || selectedMenu == currentMenu::ProgramsMenu) {
        selectedMenu = currentMenu::MainMenu;
        selectedItem = 0;

        QStringList list;
        list << "PROGRAMS" << "SETTINGS";
        menuModel->setStringList(list);
    } else if (selectedMenu == currentMenu::Form) {
        selectedMenu = currentMenu::ProgramsMenu;
        selectedItem = 0;
        frequency = 0;

        QStringList list;
        list << "ALLERGY" << "PAIN" << "INT. PAIN";
        menuModel->setStringList(list);
    } else if (selectedMenu == currentMenu::Timer) {
        selectedMenu = currentMenu::Form;
        treatmentTimer->stop();
    }

    emit valueChanged();
}

void AppModel::handleLeft() {
    if (selectedMenu == currentMenu::Form) {
        frequency -= 1;
    }

    emit valueChanged();
}

void AppModel::handleRight() {
    if (selectedMenu == currentMenu::Form) {
        frequency += 1;
    }

    emit valueChanged();
}

void AppModel::handleTop() {
    selectedItem = selectedItem > 0 ? selectedItem - 1 : selectedItem;

    emit valueChanged();
}

void AppModel::handleBottom() {
    selectedItem = selectedItem < menuModel->rowCount() ? selectedItem + 1 : selectedItem;

    emit valueChanged();
}

void AppModel::handleEnter() {
    if (selectedMenu == currentMenu::MainMenu) {
        switch (selectedItem) {
            case 0: {
                selectedMenu = currentMenu::ProgramsMenu;
                selectedItem = 0;

                QStringList list;
                list << "ALLERGY" << "PAIN" << "INT. PAIN";
                menuModel->setStringList(list);

                break;
            }
            case 1: {
                selectedMenu = currentMenu::Settings;
                break;
            }
        }
    } else if (selectedMenu == currentMenu::ProgramsMenu) {
        selectedMenu = currentMenu::Form;
    } else if (selectedMenu == currentMenu::Form) {
        selectedMenu = currentMenu::Timer;
        treatmentLeft = 100;
        treatmentTimer->start(100);
    }

    emit valueChanged();
}

void AppModel::Timer_changed() {
    batteryLeft -= 1;

    if (batteryLeft <= 0) {
        batteryTimer->stop();
    }

    emit valueChanged();
}

void AppModel::TreatmentTimer_changed() {
    treatmentLeft -= 1;

    if (treatmentLeft <= 0) {
        treatmentTimer->stop();
    }

    emit valueChanged();
}
