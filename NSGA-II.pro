#-------------------------------------------------
#
# Project created by QtCreator 2015-03-16T18:00:40
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = NSGA-II
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    gui/terminal/QtTerminal.cpp

HEADERS += \
    interfaces/Gui.h \
    gui/terminal/QtTerminal.h \
    libraries/exprtk.hpp

# add new folders here
INCLUDEPATH += interfaces/
INCLUDEPATH += gui/terminal/
INCLUDEPATH += libraries/
