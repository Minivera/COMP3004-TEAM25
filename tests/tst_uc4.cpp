#include "tst_uc4.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appmodel.h"

void UC4Test::testUC4() {
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
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    // Verify the result
    QCOMPARE(window.ui->mainView->isVisible(), true);

    listViewModel = window.ui->mainView->model();
    QCOMPARE(listViewModel->index(0, 0).data(Qt::DisplayRole).toString(), "ALLERGY");
    QCOMPARE(listViewModel->index(1, 0).data(Qt::DisplayRole).toString(), "PAIN");
    QCOMPARE(listViewModel->index(2, 0).data(Qt::DisplayRole).toString(), "INT. PAIN");

    QCOMPARE(window.ui->mainView->currentIndex().data(Qt::DisplayRole).toString(), "ALLERGY");

    // Step 2
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    // Verify the result
    QCOMPARE(window.ui->mainView->isVisible(), false);
    QCOMPARE(window.form->isVisible(), false);

    // Step 3
    QTest::mouseClick(window.ui->leftButton, Qt::LeftButton);

    // Verify the result
    QCOMPARE(model.getFrequency(), 2);

    // Step 4
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);

    // Verify the result
    QCOMPARE(window.form->isVisible(), false);
    QCOMPARE(window.timer->isVisible(), true);

    // Step 5
    QCOMPARE(window.timer->ui->successLabel->isVisible(), true);

    model.treatmentLeft = 1;
    model.TreatmentTimer_changed();
    QTest::mouseClick(window.ui->enterButton, Qt::LeftButton);
}

void UC4Test::testUC4Extend2a() {
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

void UC4Test::testUC4Extend3a();
void UC4Test::testUC4Extend4a();
void UC4Test::testUC4Extend5a();
void UC4Test::testUC4Extend5b();
void UC4Test::testUC4Extend5c();
