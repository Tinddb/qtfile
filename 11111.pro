QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    builder.cpp \
    client.cpp \
    concretebuilder.cpp \
    director.cpp \
    form1.cpp \
    kino.cpp \
    kinoadd.cpp \
    main.cpp \
    mainwindow.cpp \
    nnn.cpp \
    passticket.cpp \
    product.cpp \
    prokatadd.cpp

HEADERS += \
    builder.h \
    client.h \
    concretebuilder.h \
    director.h \
    form1.h \
    kino.h \
    kinoadd.h \
    mainwindow.h \
    nnn.h \
    passticket.h \
    product.h \
    prokatadd.h

FORMS += \
    client.ui \
    form1.ui \
    kino.ui \
    kinoadd.ui \
    mainwindow.ui \
    nnn.ui \
    passticket.ui \
    prokatadd.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    11111.pro
