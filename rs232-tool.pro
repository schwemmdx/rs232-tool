QT += widgets serialport charts

greaterThan(QT_MAJOR_VERSION, 4):

CONFIG += c++17

TARGET = RS232-Tool



SOURCES += \
    dlrdialog.cpp \
    listentry.cpp \
    main.cpp \
    mainwindow.cpp \
    oszigraph.cpp \
    readingthread.cpp \
    settingsdialog.cpp \
    writingthread.cpp

HEADERS += \
    dlrdialog.h \
    listentry.h \
    mainwindow.h \
    oszigraph.h \
    readingthread.h \
    settingsdialog.h \
    writingthread.h

FORMS += \
    dlrdialog.ui \
    mainwindow.ui \
    protocolEdit.ui \
    settingsdialog.ui

RESOURCES += \
    rs232_ressources.qrc

DESTDIR = ./build/$${TARGET}


INSTALLS += target

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += yaml-cpp # super crappy !

