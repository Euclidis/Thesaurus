#-------------------------------------------------
#
# Project created by QtCreator 2015-01-09T13:19:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Thesaurus
TEMPLATE = app


SOURCES += main.cpp \
    Windows/AccountWinow/account_window.cpp \
    Windows/AccountWinow/abstraction_aw.cpp \
    Windows/MenuWindow/menu_window.cpp \
    Windows/MenuWindow/abstraction_mw.cpp \
    DataClasses/word.cpp \
    DataClasses/ld.cpp \
    DataClasses/account.cpp \
    DataClasses/data.cpp \
    General/MyWidgets/mlabel.cpp \
    General/MyWidgets/mlineedit.cpp \
    General/MyWidgets/mscrollarea.cpp \
    General/read_write.cpp \
    General/lang_list.cpp \
    General/base_window.cpp \
    sloter.cpp


HEADERS  += \
    Windows/start.h \
    Windows/AccountWinow/account_window.h \
    Windows/AccountWinow/abstraction_aw.h \
    Windows/MenuWindow/menu_window.h \
    Windows/MenuWindow/abstraction_mw.h \
    General/MyWidgets/start.h \
    General/MyWidgets/end.h \
    General/MyWidgets/mlabel.h \
    General/MyWidgets/mlineedit.h \
    General/MyWidgets/mscrollarea.h \
    General/inclusion.h \
    Windows/end.h \
    General/constants.h \
    General/read_write.h \
    General/lang_list.h \
    General/base_window.h \
    DataClasses/lists.h \
    DataClasses/items.h \
    DataClasses/word.h \
    DataClasses/ld.h \
    DataClasses/account.h \
    DataClasses/data.h \
    sloter.h


FORMS    += \
    General/e_base_window.ui \
    Windows/AccountWinow/account_window.ui \
    Windows/MenuWindow/menu_window.ui

RESOURCES += \
    resources.qrc
