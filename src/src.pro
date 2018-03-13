TEMPLATE = app

QT += qml

DESTDIR = ../
TARGET = mqg

SOURCES += \
    main.cpp

include(Script/script.pri)
include(Service/service.pri)
include(QtModules/qt_modules.pri)

HEADERS += \
    iapplication.h
