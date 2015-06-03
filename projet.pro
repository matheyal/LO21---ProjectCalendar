#-------------------------------------------------
#
# Project created by QtCreator 2015-05-30T16:26:36
#
#-------------------------------------------------

QT += widgets
QT += xml

QT       += core

QT       -= gui

TARGET = projet
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    agenda.cpp \
    timing.cpp \
    programmation.cpp \
    evenement.cpp \
    activite.cpp \
    tache.cpp \
    tacheunitaire.cpp \
    tachecomposite.cpp \
    projet.cpp \
    fabrique.cpp \
    fabriqueactiv.cpp \
    projetmanager.cpp \
    tachepreemptable.cpp

HEADERS += \
    agenda.h \
    ../../Projet 2015/FINAL/timing-2.h \
    timing.h \
    programmation.h \
    evenement.h \
    activite.h \
    tache.h \
    tacheunitaire.h \
    tachecomposite.h \
    projet.h \
    fabrique.h \
    fabriqueactiv.h \
    projetmanager.h \
    calendar.h \
    tachepreemptable.h
