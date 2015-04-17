TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += UT
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    TestExample.cpp \
    ../genetic_algorithm/Genotype.cpp \
    genetic_algorithm/TestGenotype.cpp \
    ../genetic_algorithm/Subject.cpp \
    genetic_algorithm/TestSubject.cpp \
    ../genetic_algorithm/Generation.cpp \
    genetic_algorithm/TestGeneration.cpp \
    ../genetic_algorithm/Population.cpp \
    genetic_algorithm/TestPopulation.cpp \
    ../math/Expression.cpp \
    math/TestExpression.cpp

HEADERS += \
    ../genetic_algorithm/Genotype.h \
    ../genetic_algorithm/Subject.h \
    ../genetic_algorithm/Generation.h \
    ../genetic_algorithm/Population.h \
    ../math/Expression.h \
    ../libraries/exprtk.hpp \
    ../libraries/CustomAssertion.h

# add new folders here
INCLUDEPATH += ../genetic_algorithm/
INCLUDEPATH += ../libraries/
INCLUDEPATH += ../math/

LIBS += -lunittest++
