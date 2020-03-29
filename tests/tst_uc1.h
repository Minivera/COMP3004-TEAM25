#ifndef TST_UC1_H
#define TST_UC1_H

#include <QtTest>
#include <QPushButton>

#include <QObject>

class UC1Test : public QObject
{
    Q_OBJECT

private slots:
    void testUC1();
    void testUC1Extend1a();
};

#endif // TST_UC1_H
