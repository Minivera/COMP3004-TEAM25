#include "appmodel.h"
#include "electrode.h"

const int AppModel::lowBatteryThreshold;

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
    if (batteryLeft <= 0) {
        return;
    }

    on = true;
    selectedMenu = currentMenu::MainMenu;
    batteryTimer->start(1000);

    QStringList list;
    list << "PROGRAMS" << "FREQUENCIES" << "SETTINGS";
    menuModel->setStringList(list);

    emit valueChanged();
}

void AppModel::powerOff() {
    on = false;
    batteryTimer->stop();
    treatmentTimer->stop();

    QStringList list;
    menuModel->setStringList(list);

    emit valueChanged();
}

void AppModel::handleBack() {
    if (selectedMenu == currentMenu::Settings || selectedMenu == currentMenu::ProgramsMenu || selectedMenu == currentMenu::FrequenciesMenu) {
        selectedMenu = currentMenu::MainMenu;
        selectedItem = 0;

        QStringList list;
        list << "PROGRAMS" << "FREQUENCIES" << "SETTINGS";
        menuModel->setStringList(list);
    } else if (selectedMenu == currentMenu::FormPrograms) {
        selectedMenu = currentMenu::ProgramsMenu;
        selectedItem = 0;
        frequency = 1;

        QStringList list;
        list << "ALLERGY" << "PAIN" << "INT. PAIN";
        menuModel->setStringList(list);
    } else if (selectedMenu == currentMenu::FormFrequencies) {
        selectedMenu = currentMenu::FrequenciesMenu;
        selectedItem = 0;
        frequency = 1;

        QStringList list;
        list << "10Hz" << "20Hz" << "60Hz";
        menuModel->setStringList(list);
    } else if (selectedMenu == currentMenu::TimerPrograms) {
        selectedMenu = currentMenu::FormPrograms;
        treatmentTimer->stop();
        treatmentLeft = 100;
    } else if (selectedMenu == currentMenu::TimerFrequencies) {
        selectedMenu = currentMenu::FormFrequencies;
        treatmentTimer->stop();
        treatmentLeft = 100;
    }

    emit valueChanged();
}

void AppModel::handleMenu() {
    selectedMenu = currentMenu::MainMenu;
    selectedItem = 0;
    frequency = 1;
    treatmentLeft = 100;

    treatmentTimer->stop();

    QStringList list;
    list << "PROGRAMS" << "FREQUENCIES" << "SETTINGS";
    menuModel->setStringList(list);

    emit valueChanged();
}

void AppModel::handleLeft() {
    if (selectedMenu == currentMenu::FormPrograms || selectedMenu == currentMenu::FormFrequencies) {
        frequency -= 1;
    }

    emit valueChanged();
}

void AppModel::handleRight() {
    if (selectedMenu == currentMenu::FormPrograms || selectedMenu == currentMenu::FormFrequencies) {
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
                selectedMenu = currentMenu::FrequenciesMenu;
                selectedItem = 0;

                QStringList list;
                list << "10Hz" << "20Hz" << "60Hz";
                menuModel->setStringList(list);

                break;
            }
            case 2: {
                selectedMenu = currentMenu::Settings;
                break;
            }
        }
    } else if (selectedMenu == currentMenu::ProgramsMenu && batteryLeft > lowBatteryThreshold) {
        selectedMenu = currentMenu::FormPrograms;
    } else if (selectedMenu == currentMenu::FrequenciesMenu && batteryLeft > lowBatteryThreshold) {
        selectedMenu = currentMenu::FormFrequencies;
    } else if (selectedMenu == currentMenu::FormPrograms && batteryLeft > lowBatteryThreshold) {
        selectedMenu = currentMenu::TimerPrograms;
        treatmentLeft = 100;
        treatmentTimer->start(100);
    } else if (selectedMenu == currentMenu::FormFrequencies && batteryLeft > lowBatteryThreshold) {
        selectedMenu = currentMenu::TimerFrequencies;
        treatmentLeft = 100;
        treatmentTimer->start(100);
    }

    emit valueChanged();
}

void AppModel::Timer_changed() {
    batteryLeft -= 1;

    if (batteryLeft <= 0) {
        batteryTimer->stop();
        powerOff();
    }

    emit valueChanged();
}

void AppModel::TreatmentTimer_changed() {
    treatmentLeft -= 1;

    if (treatmentLeft <= 0) {
        treatmentTimer->stop();
    }
    if(electrode::Instance()->getState()==false){
        treatmentTimer->stop();
    }

    emit valueChanged();
}
