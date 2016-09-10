#-------------------------------------------------
#
# Project created by QtCreator 2015-03-16T18:00:40
#
#-------------------------------------------------

QT       += core  gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NSGA-II
QMAKE_CXXFLAGS += -std=c++11

TEMPLATE = app

FORMS += \
    gui/qt4/forms/mainwindow.ui

SOURCES += main.cpp \
    gui/terminal/QtTerminal.cpp \
    gui/qt4/Qt4Window.cpp \
    gui/qt4/MainWindow.cpp \
    gui/qt4/MathGlDrawer.cpp \
    genetic_algorithm/Population.cpp \
    genetic_algorithm/Generation.cpp \
    genetic_algorithm/Subject.cpp \
    math/Expression.cpp \
    genetic_algorithm/Fenotype.cpp \
    math/Functions.cpp \
    math/RandomGenerator.cpp \
    genetic_algorithm/Nsga.cpp \
    genetic_algorithm/Front.cpp \
    genetic_algorithm/Fronts.cpp

HEADERS += \
    interfaces/Gui.h \
    gui/terminal/QtTerminal.h \
    libraries/exprtk.hpp \
    gui/qt4/Qt4Window.h \
    gui/qt4/MathGlDrawer.h \
    genetic_algorithm/Population.h \
    genetic_algorithm/Generation.h \
    genetic_algorithm/Subject.h \
    math/Expression.h \
    libraries/CustomAssertion.h \
    genetic_algorithm/Fenotype.h \
    math/Functions.h \
    math/RandomGenerator.h \
    interfaces/Core.h \
    genetic_algorithm/Nsga.h \
    genetic_algorithm/Front.h \
    genetic_algorithm/Fronts.h \
    gui/qt4/QDebugStream.h \
    gui/qt4/MainWindow.h

# add new folders here
INCLUDEPATH += interfaces/
INCLUDEPATH += gui/terminal/
INCLUDEPATH += gui/qt4/
INCLUDEPATH += libraries/
INCLUDEPATH += math/
INCLUDEPATH += genetic_algorithm/

LIBS += -lmgl -lmgl-qt
