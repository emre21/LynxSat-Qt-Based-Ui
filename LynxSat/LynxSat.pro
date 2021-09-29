QT       += core gui multimedia charts serialport quickwidgets quick quick3d

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chartwidget.cpp \
    csvwriter.cpp \
    datastream.cpp \
    lynxchart.cpp \
    lynxserialport.cpp \
    main.cpp \
    mainwindow.cpp \
    mapandrender.cpp \
    videowidget.cpp

HEADERS += \
    chartwidget.h \
    csvwriter.h \
    datastream.h \
    lynxchart.h \
    lynxserialport.h \
    mainwindow.h \
    mapandrender.h \
    videowidget.h

FORMS += \
    chartwidget.ui \
    datastream.ui \
    mainwindow.ui \
    mapandrender.ui \
    videowidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../externalLib/opencv/build/x64/vc15/lib/ -lopencv_world450
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../externalLib/opencv/build/x64/vc15/lib/ -lopencv_world450d
else:unix: LIBS += -L$$PWD/../../externalLib/opencv/build/x64/vc15/lib/ -lopencv_world450

INCLUDEPATH += $$PWD/../../externalLib/opencv/build/include
DEPENDPATH += $$PWD/../../externalLib/opencv/build/include

DISTFILES +=

RESOURCES += \
    res.qrc
