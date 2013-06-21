#-------------------------------------------------
#
# Project created by QtCreator 2013-05-10T19:35:05
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HelpMeNow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logonscreen.cpp \
    abrirchamado.cpp \
    fecharchamado.cpp

HEADERS  += mainwindow.h \
    logonscreen.h \
    abrirchamado.h \
    fecharchamado.h

FORMS    += mainwindow.ui \
    logonscreen.ui \
    abrirchamado.ui \
    fecharchamado.ui
