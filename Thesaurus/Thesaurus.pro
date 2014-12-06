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
    carcass.cpp \
    base_window.cpp \
    Exceptions/exception_window.cpp \
    Exceptions/base_exception.cpp

HEADERS  += \
    carcass.h \
    adress_texts.h \
    general.h \
    base_window.h \
    Exceptions/exception_window.h \
    Exceptions/base_exception.h

FORMS    += \
    base_window.ui \
    Exceptions/exception_window.ui
