#include "tst_uc5.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_timer.h"
#include "appmodel.h"

void UC5Test::testUC5() {
    // Arrange
    AppModel model;
    MainWindow window(&model);

    window.show();
    model.powerOn();

    // Verify pre-conditions
    QCOMPARE(model.isOn(), true); // Is the model saying that the device is on?

    QCOMPARE(window.ui->mainView->isVisible(), true);

    auto listViewModel = window.ui->mainView->model();
    QCOMPARE(listViewModel->index(0, 0).data(Qt::DisplayRole).toString(), "PROGRAMS");
    QCOMPARE(listViewModel->index(1, 0).data(Qt::DisplayRole).toString(), "FREQUENCIES");
    QCOMPARE(listViewModel->index(2, 0).data(Qt::DisplayRole).toString(), "SETTINGS");

    QCOMPARE(window.ui->mainView->currentIndex().data(Qt::DisplayRole).toString(), "PROGRAMS");

    // Run the actual case set by step
    // Step 1
    QTest::mouseClick(window.ui->bottomButton, Qt::LeftButton);

    QCOMPARE(window.ui->mainView->currentIndex().data(Qt::DisplayRole).toString(), "FREQUENCIES");

    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    // Verify the result
    QCOMPARE(window.ui->mainView->isVisible(), true);

    listViewModel = window.ui->mainView->model();
    QCOMPARE(listViewModel->index(0, 0).data(Qt::DisplayRole).toString(), "10Hz");
    QCOMPARE(listViewModel->index(1, 0).data(Qt::DisplayRole).toString(), "20Hz");
    QCOMPARE(listViewModel->index(2, 0).data(Qt::DisplayRole).toString(), "60Hz");

    QCOMPARE(window.ui->mainView->currentIndex().data(Qt::DisplayRole).toString(), "10Hz");

    // Step 2
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    // Verify the result
    QCOMPARE(window.ui->mainView->isVisible(), false);
    QCOMPARE(window.form->isVisible(), true);

    // Step 3
    QTest::mouseClick(window.ui->rightButton, Qt::LeftButton);

    // Verify the result
    QCOMPARE(model.getFrequency(), 2);

    // Step 4
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    // Verify the result
    QCOMPARE(window.form->isVisible(), false);
    QCOMPARE(window.timer->isVisible(), true);

    // Step 5
    QCOMPARE(window.timer->ui->successLabel->isVisible(), false);

    model.treatmentLeft = 1;
    model.TreatmentTimer_changed();
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    QCOMPARE(window.timer->ui->successLabel->isVisible(), true);
}

void UC5Test::testUC5Extend2a() {
    // Arrange
    AppModel model;
    MainWindow window(&model);

    window.show();
    model.powerOn();

    // Prepare the extend step
    QTest::mouseClick(window.ui->bottomButton, Qt::LeftButton);

    QCOMPARE(window.ui->mainView->currentIndex().data(Qt::DisplayRole).toString(), "FREQUENCIES");

    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    // Verify we're in the right step
    auto listViewModel = window.ui->mainView->model();
    QCOMPARE(listViewModel->index(0, 0).data(Qt::DisplayRole).toString(), "10Hz");
    QCOMPARE(listViewModel->index(1, 0).data(Qt::DisplayRole).toString(), "20Hz");
    QCOMPARE(listViewModel->index(2, 0).data(Qt::DisplayRole).toString(), "60Hz");

    QCOMPARE(window.ui->mainView->currentIndex().data(Qt::DisplayRole).toString(), "10Hz");

    // Act
    QTest::mouseClick(window.ui->backButton, Qt::LeftButton);

    // Assert
    QCOMPARE(window.ui->mainView->isVisible(), true);

    listViewModel = window.ui->mainView->model();
    QCOMPARE(listViewModel->index(0, 0).data(Qt::DisplayRole).toString(), "PROGRAMS"); // We went back
    QCOMPARE(listViewModel->index(1, 0).data(Qt::DisplayRole).toString(), "FREQUENCIES");
    QCOMPARE(listViewModel->index(2, 0).data(Qt::DisplayRole).toString(), "SETTINGS");

    QCOMPARE(window.ui->mainView->currentIndex().data(Qt::DisplayRole).toString(), "PROGRAMS");
}

void UC5Test::testUC5Extend3a() {
    // Arrange
    AppModel model;
    MainWindow window(&model);

    window.show();
    model.powerOn();

    // Prepare the extend step
    QTest::mouseClick(window.ui->bottomButton, Qt::LeftButton);

    QCOMPARE(window.ui->mainView->currentIndex().data(Qt::DisplayRole).toString(), "FREQUENCIES");

    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    // Verify we're in the right step
    QCOMPARE(window.ui->mainView->isVisible(), false);
    QCOMPARE(window.form->isVisible(), true);

    // Act
    QTest::mouseClick(window.ui->backButton, Qt::LeftButton);

    // Assert
    QCOMPARE(window.ui->mainView->isVisible(), true);

    auto listViewModel = window.ui->mainView->model();
    QCOMPARE(listViewModel->index(0, 0).data(Qt::DisplayRole).toString(), "10Hz"); // We went back
    QCOMPARE(listViewModel->index(1, 0).data(Qt::DisplayRole).toString(), "20Hz");
    QCOMPARE(listViewModel->index(2, 0).data(Qt::DisplayRole).toString(), "60Hz");

    QCOMPARE(window.ui->mainView->currentIndex().data(Qt::DisplayRole).toString(), "10Hz");
}

void UC5Test::testUC5Extend4a() {
    // Arrange
    AppModel model;
    MainWindow window(&model);

    window.show();
    model.powerOn();

    // Prepare the extend step
    QTest::mouseClick(window.ui->bottomButton, Qt::LeftButton);

    QCOMPARE(window.ui->mainView->currentIndex().data(Qt::DisplayRole).toString(), "FREQUENCIES");

    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    // Verify we're in the right step
    QCOMPARE(window.ui->mainView->isVisible(), false);
    QCOMPARE(window.form->isVisible(), false);
    QCOMPARE(window.timer->isVisible(), true);

    // Act
    QTest::mouseClick(window.ui->backButton, Qt::LeftButton);

    // Assert
    QCOMPARE(window.ui->mainView->isVisible(), false);
    QCOMPARE(window.form->isVisible(), true); // We went back
    QCOMPARE(window.timer->isVisible(), false);
}

void UC5Test::testUC5Extend5a() {

    // Arrange
    AppModel model;
    MainWindow window(&model);

    window.show();
    model.powerOn();

    // Prepare the extend step
    QTest::mouseClick(window.ui->bottomButton, Qt::LeftButton);

    QCOMPARE(window.ui->mainView->currentIndex().data(Qt::DisplayRole).toString(), "FREQUENCIES");

    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    // Verify we're in the right step
    QCOMPARE(window.ui->mainView->isVisible(), false);
    QCOMPARE(window.form->isVisible(), false);
    QCOMPARE(window.timer->isVisible(), true);
    QCOMPARE(window.ui->lowBatteryLabel->isVisible(), false);

    // Act
    model.batteryLeft = 20;
    model.TreatmentTimer_changed();

    // Assert
    QCOMPARE(window.ui->mainView->isVisible(), true); // Got booted back to the main menu
    QCOMPARE(window.ui->lowBatteryLabel->isVisible(), true); // Low battery level is shown
}

void UC5Test::testUC5Extend5b() {}
void UC5Test::testUC5Extend5c() {}
