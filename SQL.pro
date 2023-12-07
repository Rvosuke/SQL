QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    createtablewindow.cpp \
    customtablemodel.cpp \
    database.cpp \
    deletedatawindow.cpp \
    homewindow.cpp \
    insertdatawindow.cpp \
    main.cpp \
    mainwindow.cpp \
    querydatawindow.cpp \
    updatedatawindow.cpp

HEADERS += \
    createtablewindow.h \
    customtablemodel.h \
    database.h \
    deletedatawindow.h \
    homewindow.h \
    insertdatawindow.h \
    mainwindow.h \
    querydatawindow.h \
    updatedatawindow.h

FORMS += \
    createtablewindow.ui \
    deletedatawindow.ui \
    homewindow.ui \
    insertdatawindow.ui \
    mainwindow.ui \
    querydatawindow.ui \
    updatedatawindow.ui

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
