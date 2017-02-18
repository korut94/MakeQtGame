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
    gamewindow.cpp

HEADERS += \
    game.h \
    world.h \
    console.h \
    gamewindow.h \
    resourceholder.h

RESOURCES += \
    resources.qrc

include(entity/entity.pri)
include(libs/libs.pri)
include(logic/logic.pri)
include(utility/utility.pri)
