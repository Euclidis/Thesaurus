#-------------------------------------------------
#
# Project created by QtCreator 2014-12-06T00:57:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Thesaurus
TEMPLATE = app


SOURCES += main.cpp\
        basewindow.cpp \
    carcass.cpp \
    Exceptions/exceptionwindow.cpp \
    Exceptions/baseexceprion.cpp

HEADERS  += basewindow.h \
    carcass.h \
    adress_texts.h \
    general.h \
    Exceptions/exceptionwindow.h \
    Exceptions/baseexceprion.h

FORMS    += basewindow.ui \
    Exceptions/exceptionwindow.ui
