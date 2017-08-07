TEMPLATE = app
QT += qml

DESTDIR = ../
TARGET = MakeQtGame

SOURCES += \
  main.cpp \
    jsengineadapterforqt.cpp \
    application.cpp \
    messageadapterforqt.cpp \
    messagehandler.cpp

HEADERS += \
    jsscriptengine.h \
    jsengineadapterforqt.h \
    application.h \
    messagehandler.h \
    messageadapterforqt.h

RESOURCES += mqg.qrc

include(Private/private.pri)
