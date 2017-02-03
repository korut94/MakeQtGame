QT += core \
      script

QT -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 \
          plugin

INCLUDEPATH += ../../

DESTDIR += ../../script

TARGET = game
TEMPLATE = lib

SOURCES += \
    mqggame.cpp

HEADERS += \
    mqggame.h
