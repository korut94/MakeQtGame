#-------------------------------------------------
#
# Project created by QtCreator 2016-11-10T20:26:19
#
#-------------------------------------------------

TEMPLATE  = subdirs
SUBDIRS  += core \
            modules

target_script.files = script/*
target_script.path  = $${OUT_PWD}/script

INSTALLS += target_script
