#-------------------------------------------------
#
# Project created by QtCreator 2018-08-05T19:37:57
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SQLiteViewer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbloader.cpp

HEADERS  += mainwindow.h \
    dbloader.h

FORMS    += mainwindow.ui
