TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

QT += core sql


SOURCES += main.cpp \
    word.cpp \
    wordcontainer.cpp \
    interface.cpp \
    date.cpp

HEADERS += \
    word.h \
    wordcontainer.h \
    interface.h \
    date.h

RESOURCES += \
    src.qrc

