#ifndef TST_UC5_H
#define TST_UC5_H

#include <QtTest>
#include <QPushButton>

#include <QObject>

class UC5Test : public QObject
{
    Q_OBJECT

private slots:
    void testUC5();
    void testUC5Extend2a();
    void testUC5Extend3a();
    void testUC5Extend4a();
    void testUC5Extend5a();
    void testUC5Extend5b();
    void testUC5Extend5c();
};

#endif // TST_UC5_H
