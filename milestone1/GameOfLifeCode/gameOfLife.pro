TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../sources/milestone1/GameOfLifeCode/main.cpp \
    ../sources/milestone1/GameOfLifeCode/matrix.cpp

SUBDIRS += \
    gameOfLife.pro

DISTFILES += \
    gameOfLife.pro.user

HEADERS += \
    ../sources/milestone1/GameOfLifeCode/matrix.h
