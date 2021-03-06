QT += testlib
QT       += core
QT       += gui


QT       += widgets

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_concordancia.cpp \
            bootstrap.cpp \
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
