#include <QtTest>
#include <QPushButton>

#include "setting.h"
#include "ui_setting.h"

class SettingTest: public QObject
{
    Q_OBJECT

private slots:
    void on_Back_clicked();
    void on_Reduce_clicked();
    void on_Add_clicked();
    void on_Decrease_clicked();
    void on_Increase_clicked();
};

void SettingTest::on_Back_clicked()
{
    // Arrange
    Setting window;

    // Act
    window.show();
    QTest::mouseClick(window.ui->Back, Qt::LeftButton);

    // Assert
    QCOMPARE(window.isHidden(), true);
}

void SettingTest::on_Reduce_clicked()
{
    // Arrange
    Setting window;

    // Act
    window.show();
    QTest::mouseClick(window.ui->Reduce, Qt::LeftButton);

    // Assert
    QCOMPARE(window.ui->Volice->text().toInt(), -1);
}

void SettingTest::on_Add_clicked()
{
    // Arrange
    Setting window;

    // Act
    window.show();
    QTest::mouseClick(window.ui->Add, Qt::LeftButton);

    // Assert
    QCOMPARE(window.ui->Volice->text().toInt(), -1);
}

void SettingTest::on_Decrease_clicked()
{
    // Arrange
    Setting window;

    // Act
    window.show();
    QTest::mouseClick(window.ui->Decrease, Qt::LeftButton);

    // Assert
    QCOMPARE(window.ui->Light->text().toInt(), -1);
}

void SettingTest::on_Increase_clicked()
{
    // Arrange
    Setting window;

    // Act
    window.show();
    QTest::mouseClick(window.ui->Increase, Qt::LeftButton);

    // Assert
    QCOMPARE(window.ui->Light->text().toInt(), -1);
}

#include "tst_setting.moc"
