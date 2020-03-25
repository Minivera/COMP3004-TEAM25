#include <QtTest>
#include <QPushButton>

#include "setting.h"
#include "ui_setting.h"

#ifndef TST_SETTING_H
#define TST_SETTING_H

class SettingTest: public QObject
{
    Q_OBJECT

private slots:
    void on_Back_clicked();
    void on_Reduce_clicked();
    void on_Add_clicked();
    void on_Decrease_clicked();
    void on_Increase_clicked();
};

#endif // TST_SETTING_H
