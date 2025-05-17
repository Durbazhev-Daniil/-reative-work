QT += core gui network widgets xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = webmonitor
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    webmonitor.cpp

HEADERS += mainwindow.h \
    webmonitor.h

FORMS += mainwindow.ui # Если используете .ui файлы

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
