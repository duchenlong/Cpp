QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 -lwpcap -lpacket -lws2_32

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
    card.cpp \
    control.cpp \
    init.cpp \
    main.cpp \
    mainwindow.cpp \
    mypcap.cpp \
    netpack.cpp \
    tcp.cpp \
    udp.cpp

HEADERS += \
    card.h \
    control.h \
    init.h \
    mainwindow.h \
    mypcap.h \
    netpack.h \
    tcp.h \
    udp.h

FORMS += \
    card.ui \
    mainwindow.ui \
    netpack.ui \
    tcp.ui \
    udp.ui

Npcap += $$PWD/npcap-sdk-1.06

INCLUDEPATH += \
    $${Npcap}/Include \
    $${Npcap}/Include/pcap

LIBS += \
    $${Npcap}/Lib/x64/Packet.lib    \
    $${Npcap}/Lib/x64/wpcap.lib     \
    $${Npcap}/Lib/Packet.lib        \
    $${Npcap}/Lib/wpcap.lib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RC_ICONS = ./design.ico
