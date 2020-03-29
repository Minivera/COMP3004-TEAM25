#include <QtTest>
#include <QApplication>

#include "tst_mainwindow.h"
#include "tst_form.h"
#include "tst_timer.h"

// Use cases tests
#include "tst_uc1.h"
#include "tst_uc2.h"
#include "tst_uc3.h"
#include "tst_uc4.h"
#include "tst_uc5.h"

int main(int argc, char *argv[])
{
    // setup lambda
    int status = 0;
    QApplication app(argc, argv);

    auto runTest = [&status, argc, argv](QObject* obj) {
        status |= QTest::qExec(obj, argc, argv);
    };

    // run suite
    runTest(new MainWindowTest);
    runTest(new FormTest);
    runTest(new TimerTest);
    runTest(new UC1Test);
    runTest(new UC2Test);
    runTest(new UC3Test);
    runTest(new UC4Test);
    runTest(new UC5Test);

    return status;
}
