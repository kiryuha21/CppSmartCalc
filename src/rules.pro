QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = SmartCalc2

SOURCES += \
    main.cpp \
    consoleView.cpp \
    exampleController.cpp \
    exampleModel.cpp

HEADERS += \
    consoleView.h \
    exampleController.h \
    exampleModel.h

#FORMS += \
#    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target