QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT += printsupport
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
TARGET = Application
INCLUDEPATH +=  E:\opencv-build\install\include
INCLUDEPATH +=  frontPage

LIBS += E:\opencv-build\bin\libopencv_core460.dll
LIBS += E:\opencv-build\bin\libopencv_highgui460.dll
LIBS += E:\opencv-build\bin\libopencv_imgcodecs460.dll
LIBS += E:\opencv-build\bin\libopencv_imgproc460.dll
LIBS += E:\opencv-build\bin\libopencv_calib3d460.dll
LIBS += E:\opencv-build\bin\libopencv_objdetect460.dll

SOURCES += \
    charreader.cpp \
    databundle.cpp \
    dotBoundaryFinder.cpp \
    dotprocessor.cpp \
    frontPage/frontpage.cpp \
    frontPage/startlabel.cpp \
    imagelabel.cpp \
    lineidentifire.cpp \
    linereader.cpp \
    main.cpp \
    dialog.cpp \
    mainwindow.cpp \
    manual.cpp \
    olistview.cpp \
    preprocessor.cpp \
    progressWidget/progresswidget.cpp \
    charDebugWidget/chardebug.cpp \
    scalevaraibles.cpp \
    utilfileanddir.cpp \
    utilimageprocfordialog.cpp

HEADERS += \
    CommonSymbols.h \
    bangla.h \
    charreader.h \
    dotBoundaryFinder.h \
    dotprocessor.h \
    english.h \
    banglaTextProcess.h \
    brailleToBangla.h \
    brailleToText.h \
    databundle.h \
    dialog.h \
    double_map.h \
    frontPage/frontpage.h \
    frontPage/startlabel.h \
    imagelabel.h \
    lineidentifire.h \
    linereader.h \
    mainwindow.h \
    manual.h \
    olistview.h \
    preprocessor.h \
    progressWidget/progresswidget.h \
    charDebugWidget/chardebug.h \
    scalevaraibles.h \
    splitText.h \
    utilfileanddir.h \
    utilimageprocfordialog.h



FORMS += \
    frontPage/frontpage.ui \
    mainwindow.ui \
    manual.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

SUBDIRS += \
    frontPage/frontPage1.pro
