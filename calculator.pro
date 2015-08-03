#-------------------------------------------------
#
# Project created by QtCreator 2015-07-30T18:37:25
#
#-------------------------------------------------

QT       += core gui

QMAKE_LFLAGS = -static -static-libgcc -static-libstdc++

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calculator
TEMPLATE = app

SOURCES += main.cpp\
        window.cpp

HEADERS  += window.h
