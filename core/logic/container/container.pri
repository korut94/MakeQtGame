HEADERS += \
    $$PWD/builder.h \
    $$PWD/container.h \
    $$PWD/containerbook.h \
    $$PWD/loader.h \
    $$PWD/dependencies.h

SOURCES += \
    $$PWD/builder.cpp \
    $$PWD/containerbook.cpp

include(loader/loader.pri)
