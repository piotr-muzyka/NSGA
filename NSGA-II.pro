#-------------------------------------------------
#
# Project created by QtCreator 2015-03-16T18:00:40
#
#-------------------------------------------------

QT       += core  gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NSGA-II
<<<<<<< HEAD

TEMPLATE = app

=======
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

>>>>>>> 54a7326f98b8a17f22f682e7bddb938529e04e9f
FORMS += \
    gui/qt4/forms/mainwindow.ui

SOURCES += main.cpp \
    gui/terminal/QtTerminal.cpp \
    math/ExpressionParser.cpp \
    gui/qt4/Qt4Window.cpp \
    gui/qt4/MainWindow.cpp \
    gui/qt4/MathGlDrawer.cpp

HEADERS += \
    interfaces/Gui.h \
    gui/terminal/QtTerminal.h \
    libraries/exprtk.hpp \
    math/ExpressionParser.h \
    gui/qt4/Qt4Window.h \
    gui/qt4/MainWindow.h \
    gui/qt4/MathGlDrawer.h

# add new folders here
INCLUDEPATH += interfaces/
INCLUDEPATH += gui/terminal/
INCLUDEPATH += gui/qt4/
INCLUDEPATH += libraries/
INCLUDEPATH += math/

<<<<<<< HEAD
LIBS += -lmgl -lmgl-qt
=======
LIBS += -Llibraries -lmgl -lmgl-qt -lgomp

OTHER_FILES += \
    .travis.yml \
    libraries/build_libs.sh
>>>>>>> 54a7326f98b8a17f22f682e7bddb938529e04e9f
