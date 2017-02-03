QT += core \
      gui \
      script

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 \
          plugin

DESTDIR += ../../../libs/entity
INCLUDEPATH += ../../../

TARGET = boxman
TEMPLATE = lib

HEADERS += \
    boxmanplugin.h \
    boxman.h

SOURCES += \
    boxmanplugin.cpp \
    boxman.cpp
