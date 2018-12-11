QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testiterator.cpp \
    ../elasticnet.cpp \
    ../iterable.cpp \
    ../iterator.cpp

HEADERS += \
    ../elasticnet.h \
    ../iterable.h \
    ../iterator.h
