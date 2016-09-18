TEMPLATE = app

QT += qml quick widgets quickcontrols2

CONFIG += c++11

SOURCES += main.cpp \
    item.cpp \
    tvshow.cpp \
    udpsocket.cpp \
    server.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    item.h \
    tvshow.h \
    udpsocket.h \
    server.h

DISTFILES +=
