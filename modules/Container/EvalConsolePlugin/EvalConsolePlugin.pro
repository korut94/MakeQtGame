CONFIG      += c++14 plugin
DESTDIR     += ../../../libs/container
INCLUDEPATH += ../../../
TARGET       = $$qtLibraryTarget(evalconsole)
TEMPLATE     = lib

QT += core \
      gui \
      script

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    evalconsoleplugin.h \
    lconsole.h \
    lengine.h \
    ../../../core/logic/container/builder.h \
    ../../../core/logic/abstractlogic.h \
    ../../../core/logic/unit.h

SOURCES += \
    evalconsoleplugin.cpp \
    lconsole.cpp \
    lengine.cpp \
    ../../../core/logic/container/builder.cpp \
    ../../../core/logic/abstractlogic.cpp \
    ../../../core/logic/unit.cpp
