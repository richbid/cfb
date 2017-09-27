#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T07:55:56
#
#-------------------------------------------------

QT       += core xml

TARGET = inheritance1
TEMPLATE = app
#TEMPLATE = lib
#CONFIG   += staticlib

SOURCES += main.cpp \
	threads.cpp \
	qjson.cpp \
ns/cls.cpp \
ns/cls2.cpp \
    values.cpp \
    log.cpp

HEADERS  += config.h \
    filesys.h \
    memio.h \
    threads.h \
    qjson.h \
ns/ife.h \
ns/cls.h \
ns/cls2.h \
    values.h \
    log.h

#relative include .lib / .a, ignore library ext name
#LIBS += -l$$PWD/inheritance1

QMAKE_LFLAGS_RELEASE = -static-libgcc -static-libstdc++ -static
