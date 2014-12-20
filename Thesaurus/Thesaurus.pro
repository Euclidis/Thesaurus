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
    Exceptions/base_exception.cpp \
    Exceptions/ex_file_not_found.cpp \
    Windows/account_window.cpp \
    Exceptions/ex_file_not_open.cpp \
    Windows/write_words_window.cpp \
    Exceptions/ex_unexpected.cpp \
    Windows/message_window.cpp \
    Exceptions/ex_config_error.cpp \
    Exceptions/exception_window.cpp \
    Exceptions/ex_some_show.cpp \
    Windows/lang_selection_window.cpp \
    Windows/menu_window.cpp \
    Windows/MyWidgets/label.cpp \
    sloter.cpp \
    Windows/reset_pass_window.cpp \
    Windows/mesokcancel.cpp \
    language.cpp \
    Implementation/learning_direction.cpp \
    Implementation/www_realization.cpp \
    Windows/dct_window.cpp \
    lang_list.cpp \
    Implementation/menu_abstraction.cpp

HEADERS  += \
    carcass.h \
    adress_texts.h \
    general.h \
    base_window.h \
    Exceptions/base_exception.h \
    Exceptions/ex_file_not_found.h \
    exceptions_list.h \
    Windows/account_window.h \
    Exceptions/ex_file_not_open.h \
    Windows/write_words_window.h \
    Exceptions/ex_unexpected.h \
    Windows/message_window.h \
    Exceptions/ex_config_error.h \
    Exceptions/exception_window.h \
    Exceptions/ex_some_show.h \
    Windows/lang_selection_window.h \
    Windows/menu_window.h \
    Windows/MyWidgets/label.h \
    sloter.h \
    Windows/reset_pass_window.h \
    Windows/mesokcancel.h \
    language.h \
    Implementation/learning_direction.h \
    Implementation/www_realization.h \
    Windows/dct_window.h \
    Implementation/menu_abstraction.h


FORMS    += \
    base_window.ui \
    Windows/account_window.ui \
    Windows/write_words_window.ui \
    Windows/message_window.ui \
    Exceptions/exception_window.ui \
    Windows/lang_selection_window.ui \
    Windows/menu_window.ui \
    Windows/mesokcancel.ui \
    Windows/reset_pass_window.ui \
    Windows/dct_window.ui

RESOURCES += \
    Fonts.qrc
