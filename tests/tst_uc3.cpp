#include "tst_uc3.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appmodel.h"

void UC3Test::testUC3() {
    // Arrange
    AppModel model;
    MainWindow window(&model);

    window.show();
    model.powerOn();

    // Verify pre-conditions
    QCOMPARE(model.isOn(), true); // Is the model saying that the device is on?

    QCOMPARE(window.ui->mainView->isVisible(), true);
    QCOMPARE(window.set->isVisible(), false);

    // Act
    QTest::mouseClick(window.ui->bottomButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->bottomButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    // Assert
    QCOMPARE(window.ui->mainView->isVisible(), false);
    QCOMPARE(window.set->isVisible(), true);
}

void UC3Test::testUC3Extend2a() {
    // Arrange
    AppModel model;
    MainWindow window(&model);

    window.show();
    model.powerOn();

    // Move to the settings window
    QTest::mouseClick(window.ui->bottomButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->bottomButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    // Verify pre-conditions
    QCOMPARE(window.ui->mainView->isVisible(), false);
    QCOMPARE(window.set->isVisible(), true);

    // Act
    QTest::mouseClick(window.ui->backButton, Qt::LeftButton);

    // Assert
    QCOMPARE(window.ui->mainView->isVisible(), true);
    QCOMPARE(window.set->isVisible(), false);
}
