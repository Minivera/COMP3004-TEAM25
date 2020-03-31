#include "tst_timer.h"

void TimerTest::on_Update_requested()
{
    // Arrange
    AppModel model;
    Timer widget(&model);
    electrode::Instance()->changeState();

    // Act
    widget.show();
    // Enter programs mode
    model.handleEnter();
    // Enter first program mode
    model.handleEnter();

    QSignalSpy spy(widget.model, SIGNAL(valueChanged()));

    // Enter timer
    model.handleEnter();

    // Assert
    QCOMPARE(spy.isValid(), true);
    QVERIFY(spy.wait());
}
