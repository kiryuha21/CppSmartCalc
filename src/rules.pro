QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = SmartCalc2
LIBS += -lgtest

SOURCES += \
    model/PolishEvaluation.cpp \
    tests/parsing_suite.cpp \
    tests/tests_main.cpp

HEADERS += \
    model/PolishEvaluation.h

#FORMS += \
#    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
