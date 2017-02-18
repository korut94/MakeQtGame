CONFIG      += c++14 plugin
DESTDIR     += ../../../libs/container
INCLUDEPATH += ../../../
TARGET       = $$qtLibraryTarget(evalconsole)
TEMPLATE     = lib

QT += core \
      gui \
      script

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# It's necessary to add the header and source files for the logic components,
# how the below stackoverflow page suggestes, to avoid the undefined symbol
# error:
# http://stackoverflow.com/questions/14056149/qtplugin-cannot-load-library

HEADERS += \
    evalconsoleplugin.h \
    lconsole.h \
    lengine.h \
    ../../../core/logic/abstractlogic.h \
    ../../../core/logic/unit.h \
    ../../../core/logic/container/builder.h

SOURCES += \
    evalconsoleplugin.cpp \
    lconsole.cpp \
    lengine.cpp \
    ../../../core/logic/abstractlogic.cpp \
    ../../../core/logic/unit.cpp \
    ../../../core/logic/container/builder.cpp
