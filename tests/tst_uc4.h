#ifndef TST_UC4_H
#define TST_UC4_H

#include <QtTest>
#include <QPushButton>

#include <QObject>

class UC4Test : public QObject
{
    Q_OBJECT

private slots:
    void testUC4();
    void testUC4Extend2a();
    void testUC4Extend3a();
    void testUC4Extend4a();
    void testUC4Extend5a();
    void testUC4Extend5b();
    void testUC4Extend5c();
};

#endif // TST_UC4_H
