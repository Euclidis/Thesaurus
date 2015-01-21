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
    I_General/c_read_write.cpp \
    I_General/d_lang_list.cpp \
    IV_DataClasses/c_word.cpp \
    IV_DataClasses/d_ld.cpp \
    IV_DataClasses/e_account.cpp \
    I_General/e_base_window.cpp \
    V_Windows/AccountWinow/account_window.cpp \
    V_Windows/AccountWinow/abstraction_aw.cpp \
    V_Windows/MyWidgets/a2_mlineedit.cpp \
    V_Windows/MyWidgets/a1_mlabel.cpp \
    V_Windows/MenuWindow/menu_window.cpp \
    V_Windows/MenuWindow/abstraction_mw.cpp \
    V_Windows/MyWidgets/a3_mscrollarea.cpp \
    IV_DataClasses/f_data.cpp


HEADERS  += \
    I_General/a_inclusion.h \
    I_General/b_constants.h \
    I_General/c_read_write.h \
    I_General/d_lang_list.h \
    IV_DataClasses/c_word.h \
    IV_DataClasses/a_lists.h \
    IV_DataClasses/e_account.h \
    IV_DataClasses/d_ld.h \
    IV_DataClasses/b_items.h \
    I_General/e_base_window.h \
    V_Windows/start.h \
    IV_DataClasses/f_data.h \
    V_Windows/AccountWinow/account_window.h \
    V_Windows/AccountWinow/abstraction_aw.h \
    V_Windows/MyWidgets/a2_mlineedit.h \
    V_Windows/MyWidgets/b_list_my_widgets.h \
    V_Windows/MyWidgets/a1_mlabel.h \
    V_Windows/MenuWindow/menu_window.h \
    V_Windows/MenuWindow/abstraction_mw.h \
    V_Windows/MyWidgets/a3_mscrollarea.h


FORMS    += \
    I_General/e_base_window.ui \
    V_Windows/AccountWinow/account_window.ui \
    V_Windows/MenuWindow/menu_window.ui

RESOURCES += \
    resources.qrc
