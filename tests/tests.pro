QT += testlib
QT += gui
QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

INCLUDEPATH += \
    ../app

HEADERS += \
    ../app/mainwindow.h \
    ../app/form.h \
    ../app/setting.h \
    ../app/timer.h \
    tst_form.h \
    tst_mainwindow.h \
    tst_setting.h \
    tst_timer.h

SOURCES +=  \
    ../app/mainwindow.cpp \
    ../app/form.cpp \
    ../app/setting.cpp \
    ../app/timer.cpp \
    main.cpp \
    tst_form.cpp \
    tst_mainwindow.cpp \
    tst_setting.cpp \
    tst_timer.cpp

FORMS += \
    ../app/mainwindow.ui \
    ../app/form.ui \
    ../app/setting.ui \
    ../app/timer.ui
