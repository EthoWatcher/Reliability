QT       += core
QT       += gui
QT       += widgets

TEMPLATE = lib
DEFINES += AGREEMENT_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agreement.cpp \
    ..\bootstrap.cpp \
    ..\ethowatcher.cpp\
    ..\concordance.cpp \
    ..\relatorio_paper.cpp


HEADERS += \
    Agreement_global.h \
    agreement.h \
    ..\bootstrap.h \
    ..\ethowatcher.h \
    ..\concordance.h \
    ..\relatorio_paper.h

RESOURCES += \
    ..\script.qrc

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
