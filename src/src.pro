TEMPLATE = app

CONFIG -= qt
# Required by boost::dll which includes boost::filesystem
LIBS += -lboost_system -lboost_filesystem -ldl

DESTDIR = ../
TARGET = mqg

SOURCES += \
    main.cpp

HEADERS += \
    iapplication.h

include(Plugin/plugin.pri)
include(Script/script.pri)
include(Service/service.pri)
