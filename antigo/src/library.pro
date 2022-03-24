
QT       += core
QT       += gui


QT       += widgets

DEFINES += MAKE_TEST_LIB

CONFIG += staticlib
#CONFIG -= app_bundle

TEMPLATE = lib

SOURCES +=  bootstrap.cpp \
            ethowatcher.cpp\
            concordance.cpp \
            relatorio_paper.cpp


HEADERS += \
    bootstrap.h \
    ethowatcher.h \
    concordance.h \
    relatorio_paper.h

RESOURCES += \
    script.qrc
