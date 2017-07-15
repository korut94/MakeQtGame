TEMPLATE = app
QT += qml

DESTDIR = ../
TARGET = MakeQtGame

SOURCES += \
  engine.cpp \
  environment.cpp \
  main.cpp
HEADERS += \
  engine.h \
  environment.h
RESOURCES += mqg.qrc
