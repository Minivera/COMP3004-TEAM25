#ifndef APPMODEL_H
#define APPMODEL_H

#include <QObject>
#include <QStringListModel>
#include <QModelIndex>
#include <QTimer>

enum class currentMenu { MainMenu, ProgramsMenu, FrequenciesMenu, Settings, FormPrograms, FormFrequencies, TimerPrograms, TimerFrequencies };

class AppModel : public QObject
{
    Q_OBJECT
public:
    explicit AppModel(QObject *parent = nullptr);
    ~AppModel();

    // Method that control the power on
    void powerOn();
    void powerOff();

    // Methods that control the act of going back in menus.
    void handleBack();
    void handleMenu();

    // Handles the result of the directional pad
    void handleLeft();
    void handleRight();
    void handleTop();
    void handleBottom();

    // Handles the central enter button
    void handleEnter();

    // getters
    inline bool isOn() { return on; }
    inline currentMenu getSelectedMenu() { return selectedMenu; }
    inline QStringListModel* getListViewMenuModel() { return menuModel; }
    inline QModelIndex getSelectedItem() { return menuModel->index(selectedItem, 0); }
    inline int getBatteryTime() { return batteryLeft; }
    inline int getFrequency() { return frequency; }
    inline int getTreatmentTime() { return treatmentLeft; }
signals:
    void valueChanged();

private slots:
    void Timer_changed();
    void TreatmentTimer_changed();

private:
    // If the device is on or off.
    bool on = false;

    // The currently selected menu
    currentMenu selectedMenu = currentMenu::MainMenu;

    // The model for the list view which pwoers the menu
    QStringListModel* menuModel;
    int selectedItem = 0;

    // The timer for the battery.
    QTimer* batteryTimer;
    int batteryLeft = 100;

    // Selected frequency for the treatment.
    int frequency = 1;

    // The timer for the treatment.
    QTimer* treatmentTimer;
    int treatmentLeft = 100;
};

#endif // APPMODEL_H
