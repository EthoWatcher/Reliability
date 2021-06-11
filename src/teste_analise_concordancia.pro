#-------------------------------------------------
#
# Project created by QtCreator 2021-06-07T18:05:08
#
#-------------------------------------------------

QT       += testlib

QT       += core
QT       += gui


QT       += widgets



TARGET = tst_teste_analise_concordanciatest
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++11


TEMPLATE = app


SOURCES += tst_teste_analise_concordanciatest.cpp \
    ethowatcher.cpp \
    concordance.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ethowatcher.h \
    concordance.h
