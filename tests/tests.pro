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
    ../app/form_2.h \
    ../app/form_3.h \
    ../app/setting.h \
    ../app/timer.h \
    ../app/timer_2.h \
    ../app/timer_3.h \
    tst_form.h \
    tst_mainwindow.h \
    tst_setting.h \
    tst_timer.h

SOURCES +=  \
    ../app/mainwindow.cpp \
    ../app/form.cpp \
    ../app/form_2.cpp \
    ../app/form_3.cpp \
    ../app/setting.cpp \
    ../app/timer.cpp \
    ../app/timer_2.cpp \
    ../app/timer_3.cpp \
    main.cpp \
    tst_form.cpp \
    tst_mainwindow.cpp \
    tst_setting.cpp \
    tst_timer.cpp

FORMS += \
    ../app/mainwindow.ui \
    ../app/form.ui \
    ../app/form_2.ui \
    ../app/form_3.ui \
    ../app/setting.ui \
    ../app/timer.ui \
    ../app/timer_2.ui \
    ../app/timer_3.ui
