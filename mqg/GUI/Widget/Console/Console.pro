QT       += qml quick

TARGET    =  Console
TEMPLATE  =  lib

DISTFILES += \
    console.qml \
    qmldir

consoleplugin.files += \
  console.qml \
  qmldir

consoleplugin.path += $${OUT_PWD}

INSTALLS += consoleplugin
