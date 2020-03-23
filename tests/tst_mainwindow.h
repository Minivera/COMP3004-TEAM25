#include <QtTest>
#include <QPushButton>

#include "mainwindow.h"
#include "form.h"
#include "setting.h"
#include "ui_mainwindow.h"

#ifndef TST_MAINWINDOW_H
#define TST_MAINWINDOW_H

class MainWindowTest: public QObject
{
    Q_OBJECT

private slots:
    void on_Open_clicked();
    void on_Off_clicked();
    void on_Back_clicked();
    void on_Set_clicked();
};

#endif // TST_MAINWINDOW_H
