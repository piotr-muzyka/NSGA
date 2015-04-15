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
    math/ExpressionParser.cpp \
    gui/qt4/Qt4Window.cpp \
    gui/qt4/MainWindow.cpp \
    gui/qt4/MathGlDrawer.cpp \
    genetic_algorithm/Population.cpp \
    genetic_algorithm/Generation.cpp \
    genetic_algorithm/Subject.cpp \
    genetic_algorithm/Genotype.cpp

HEADERS += \
    interfaces/Gui.h \
    gui/terminal/QtTerminal.h \
    libraries/exprtk.hpp \
    math/ExpressionParser.h \
    gui/qt4/Qt4Window.h \
    gui/qt4/MainWindow.h \
    gui/qt4/MathGlDrawer.h \
    genetic_algorithm/Population.h \
    genetic_algorithm/Generation.h \
    genetic_algorithm/Subject.h \
    genetic_algorithm/Genotype.h

# add new folders here
INCLUDEPATH += interfaces/
INCLUDEPATH += gui/terminal/
INCLUDEPATH += gui/qt4/
INCLUDEPATH += libraries/
INCLUDEPATH += math/
INCLUDEPATH += genetic_algorithm/

LIBS += -lmgl -lmgl-qt
