QT += widgets serialport charts gamepad xml

greaterThan(QT_MAJOR_VERSION, 4):

CONFIG += c++17


VERSION = 0.1.2

QT_PROJECT_NAME = rs232-tool
TARGET = $${QT_PROJECT_NAME}_$${VERSION}



SOURCES += \
    gamepad_dialog.cpp \
    gamepadthread.cpp \
    listentry.cpp \
    loopdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    osziview.cpp \
    readingthread.cpp \
    rs232scriptparser.cpp \
    settingsdialog.cpp \
    writingthread.cpp

HEADERS += \
    gamepad_dialog.h \
    gamepadthread.h \
    listentry.h \
    loopdialog.h \
    mainwindow.h \
    osziview.h \
    readingthread.h \
    rs232scriptparser.h \
    settingsdialog.h \
    writingthread.h

FORMS += \
    gamepad_dialog.ui \
    loopdialog.ui \
    mainwindow.ui \
    osziview.ui \
    settingsdialog.ui

RESOURCES += \
    rs232-tool.qrc

DESTDIR = ./bin




unix: CONFIG += link_pkgconfig
#unix: PKGCONFIG += yaml-cpp # super crappy !




