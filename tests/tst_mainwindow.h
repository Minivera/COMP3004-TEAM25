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
    void on_onButton_clicked();
    void on_backButton_clicked();
    void on_upButton_clicked();
    void on_bottomButton_clicked();
    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_enterButton_clicked();
};

#endif // TST_MAINWINDOW_H
