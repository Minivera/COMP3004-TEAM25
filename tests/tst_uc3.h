#ifndef TST_UC3_H
#define TST_UC3_H

#include <QtTest>
#include <QPushButton>

#include <QObject>

class UC3Test : public QObject
{
    Q_OBJECT

private slots:
    void testUC3();
    void testUC3Extend2a();
};

#endif // TST_UC3_H
