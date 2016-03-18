#-------------------------------------------------
#
# Project created by QtCreator 2016-03-15T13:48:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = os_sim
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    simulationwindow.cpp \
    FirstComeFirstServed.cpp \
    Process.cpp

HEADERS  += mainwindow.h \
    simulationwindow.h \
    SchedulingAlgorithm.h \
    Process.h \
    RoundRobin.h \
    FirstComeFirstServed.h

FORMS    += mainwindow.ui \
    simulationwindow.ui
