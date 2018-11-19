TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    matrix.cpp

SUBDIRS += \
    gameOfLife.pro

DISTFILES += \
    gameOfLife.pro.user

HEADERS += \
    matrix.h
