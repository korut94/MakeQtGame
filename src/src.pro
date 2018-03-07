TEMPLATE = app

DESTDIR = ../
TARGET = mqg

SOURCES += \
    main.cpp

include(Script/script.pri)
include(Service/service.pri)
