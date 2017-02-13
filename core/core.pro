CONFIG   += c++14
DESTDIR   = ../
TARGET    = make_qt_game
TEMPLATE  = app

QT += core \
      gui \
      script

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    game.cpp \
    world.cpp \
    console.cpp \
    gamewindow.cpp \
    entitybook.cpp \
    envproxyentityloader.cpp

HEADERS += \
    game.h \
    world.h \
    console.h \
    gamewindow.h \
    singleton.h \
    entityinterface.h \
    entitybook.h \
    resourceloader.h \
    abstractresourceloader.h \
    envproxyentityloader.h \
    loadplugingame.h \
    abstractentityloader.h \
    entityloader.h \
    functionentityloader.h \
    type_list.h \
    extract.h \
    apply.h \
    containerinterface.h

RESOURCES += \
    resources.qrc

include(logic/logic.pri)
