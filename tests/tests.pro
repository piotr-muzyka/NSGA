TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    TestExample.cpp \
    ../genetic_algorithm/Genotype.cpp \
    genetic_algorithm/TestGenotype.cpp

HEADERS += \
    ../genetic_algorithm/Genotype.h

# add new folders here
INCLUDEPATH += ../genetic_algorithm/

LIBS += -lunittest++
