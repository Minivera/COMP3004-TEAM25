QT += testlib
QT += gui
QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

INCLUDEPATH += \
    ../app

HEADERS += \
    ../app/appmodel.h \
    ../app/mainwindow.h \
    ../app/form.h \
    ../app/setting.h \
    ../app/timer.h \
    tst_form.h \
    tst_mainwindow.h \
    tst_timer.h \
    tst_uc1.h \
    tst_uc2.h \
    tst_uc3.h \
    tst_uc4.h

SOURCES +=  \
    ../app/appmodel.cpp \
    ../app/mainwindow.cpp \
    ../app/form.cpp \
    ../app/setting.cpp \
    ../app/timer.cpp \
    main.cpp \
    tst_form.cpp \
    tst_mainwindow.cpp \
    tst_timer.cpp \
    tst_uc1.cpp \
    tst_uc2.cpp \
    tst_uc3.cpp \
    tst_uc4.cpp

FORMS += \
    ../app/mainwindow.ui \
    ../app/form.ui \
    ../app/setting.ui \
    ../app/timer.ui
