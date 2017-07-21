QT       += qml quick

TARGET    =  Console
TEMPLATE  =  lib

DISTFILES += \
    qmldir \
    Console.qml \
    Header.qml \
    OutputLine.qml \
    Log.qml \
    Command.qml \
    Error.qml \
    Result.qml \
    Warning.qml \
    Badge.qml \
    Job.qml

consoleplugin.files += \
  Badge.qml \
  Command.qml \
  Console.qml \
  Error.qml \
  Header.qml \
  Job.qml \
  Log.qml \
  OutputLine.qml \
  Result.qml \
  Warning.qml \
  qmldir

consoleplugin.path += $${OUT_PWD}

INSTALLS += consoleplugin
