QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcommand.cpp \
    comboboxdelegate.cpp \
    deletecommand.cpp \
    doublespinboxdelegate.cpp \
    imageeditdelegate.cpp \
    main.cpp \
    mainwindow.cpp \
    objectinfo.cpp \
    objectmodel.cpp \
    propertyeditwidget.cpp \
    propertymodel.cpp \
    spinboxdelegate.cpp

HEADERS += \
    addcommand.h \
    comboboxdelegate.h \
    deletecommand.h \
    doublespinboxdelegate.h \
    imageeditdelegate.h \
    mainwindow.h \
    objectinfo.h \
    objectmodel.h \
    propertyeditwidget.h \
    propertymodel.h \
    spinboxdelegate.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    output.json \
    scale_1200.jpg
