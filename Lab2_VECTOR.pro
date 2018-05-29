QT += widgets

TARGET = Lab2_VECTOR
TEMPLATE = app

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        solver.cpp \
        dialog.cpp \
    rowinput.cpp

HEADERS += \
        mainwindow.h \
        solver.h \
        dialog.h \
    rowinput.h

FORMS += \
        mainwindow.ui \
        dialog.ui

RC_ICONS = Stacked-Boxes-Icon.ico
