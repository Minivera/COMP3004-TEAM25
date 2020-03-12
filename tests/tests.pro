QT += testlib
QT += gui
QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

INCLUDEPATH += \
    ../app

HEADERS += \
    ../app/mainwindow.h

SOURCES +=  \
    ../app/mainwindow.cpp \
    tst_mainwindow.cpp

FORMS += \
    ../app/mainwindow.ui
