#include "tst_form.h"

#include "timer.h"

void FormTest::on_Menu_clicked()
{
    // Arrange
    /*Form window;

    // Act
    window.show();
    //QTest::mouseClick(window.ui->Menu, Qt::LeftButton);

    // Assert
    QCOMPARE(window.isHidden(), true);*/
}

void FormTest::on_Reduce_clicked()
{
    // Arrange
    /*Form window;

    // Act
    window.show();
    //QTest::mouseClick(window.ui->Reduce, Qt::LeftButton);

    // Assert
    QCOMPARE(window.ui->Level->text().toInt(), -1);*/
}

void FormTest::on_Add_clicked()
{
    // Arrange
    /*Form window;

    // Act
    window.show();
    //QTest::mouseClick(window.ui->Add, Qt::LeftButton);

    // Assert
    QCOMPARE(window.ui->Level->text().toInt(), 1);*/
}

void FormTest::on_Enter_clicked()
{
    // Arrange
    /*Form window;

    // Act
    window.show();
    //QTest::mouseClick(window.ui->Enter, Qt::LeftButton);

    auto form = window.findChildren<Timer*>();

    // Assert
    QCOMPARE(form.isEmpty(), false);
    QCOMPARE(form.at(0)->objectName(), "Timer");*/
}
