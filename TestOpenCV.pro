#-------------------------------------------------
#
# Project created by QtCreator 2015-11-18T10:50:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestOpenCV
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

unix {
CONFIG += link_pkgconfig
PKGCONFIG += opencv
}
