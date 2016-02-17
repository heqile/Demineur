#-------------------------------------------------
#
# Project created by QtCreator 2016-02-16T03:17:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Demineur
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    block.cpp \
    blockarea.cpp \
    user_interface.cpp

HEADERS  += dialog.h \
    block.h \
    blockarea.h \
    user_interface.h

FORMS    += dialog.ui

RESOURCES += \
    resc.qrc
