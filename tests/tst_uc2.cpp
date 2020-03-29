#include "tst_uc2.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appmodel.h"

void UC2Test::testUC2() {
    // Arrange
    AppModel model;
    MainWindow window(&model);

    window.show();
    model.powerOn();

    // Verify pre-conditions
    QCOMPARE(model.isOn(), true); // Is the model saying that the device is on?

    // Verify that the UI looks as expected
    QCOMPARE(window.ui->mainView->isVisible(), true);
    QCOMPARE(window.ui->battery->isVisible(), true);
    QCOMPARE(window.ui->battery->text(), "100");

    auto listViewModel = window.ui->mainView->model();
    QCOMPARE(listViewModel->index(0, 0).data(Qt::DisplayRole).toString(), "PROGRAMS");
    QCOMPARE(listViewModel->index(1, 0).data(Qt::DisplayRole).toString(), "FREQUENCIES");
    QCOMPARE(listViewModel->index(2, 0).data(Qt::DisplayRole).toString(), "SETTINGS");

    QCOMPARE(window.ui->mainView->currentIndex().data(Qt::DisplayRole).toString(), "PROGRAMS");

    // Act
    QTest::mouseClick(window.ui->onButton, Qt::LeftButton);

    // Assert
    QCOMPARE(model.isOn(), false); // Is the model saying that the device is on?

    QCOMPARE(window.ui->mainView->isVisible(), false);
    QCOMPARE(window.ui->battery->isVisible(), false);
}
