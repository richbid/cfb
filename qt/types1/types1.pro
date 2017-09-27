#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T07:55:56
#
#-------------------------------------------------

QT       += core xml

TARGET = types1
TEMPLATE = app
#TEMPLATE = lib
#CONFIG   += staticlib

SOURCES += main.cpp \
	threads.cpp \
	qjson.cpp \
ns/cls0.cpp \
qtns/cls.cpp \
    values.cpp \
    log.cpp

HEADERS  += config.h \
    filesys.h \
    memio.h \
    threads.h \
    qjson.h \
ns/cls0.h \
qtns/cls.h \
    values.h \
    log.h

#relative include .lib / .a, ignore library ext name
#LIBS += -l$$PWD/types1

QMAKE_LFLAGS_RELEASE = -static-libgcc -static-libstdc++ -static
