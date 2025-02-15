QT       += core gui
QT       += charts serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    aboutdialog.cpp \
    faqdialog.cpp \
    manualdialog.cpp \
    methoddialog.cpp\
    queuedialog.cpp \
    queuesettingdialog.cpp \
    recorddialog.cpp \
    revisedialog.cpp \
    sampledialog.cpp \

HEADERS += \
    mainwindow.h \
    aboutdialog.h \
    faqdialog.h \
    manualdialog.h \
    methoddialog.h \
    queuedialog.h \
    queuesettingdialog.h \
    recorddialog.h \
    revisedialog.h \
    sampledialog.h \

INCLUDEPATH += include

SOURCES += \
        src/Utils.cpp \
        src/Toolkit.cpp \
        src/AboutDialogEx.cpp \
        src/FAQDialogEx.cpp \
        src/MainWindowEx.cpp \
        src/ManualDialogEx.cpp \
        src/MethodDialogEx.cpp \
        src/QueueDialogEx.cpp \
        src/QueueSettingDialogEx.cpp \
        src/RecordDialogEx.cpp \
        src/ReviseDialogEx.cpp \
        src/SampleDialogEx.cpp \

HEADERS += \
        include/Utils.h
        include/Toolkit.h
        include/AboutDialogEx.h
        include/FAQDialogEx.h
        include/MainWindowEx.h
        include/ManualDialogEx.h
        include/MethodDialogEx.h
        include/QueueDialogEx.h
        include/QueueSettingDialogEx.h
        include/RecordDialogEx.h
        include/ReviseDialogEx.h
        include/SampleDialogEx.h

FORMS += \
    mainwindow.ui \
    aboutdialog.ui \
    faqdialog.ui \
    manualdialog.ui \
    methoddialog.ui \
    queuedialog.ui \
    queuesettingdialog.ui \
    recorddialog.ui \
    revisedialog.ui \
    sampledialog.ui \

RESOURCES += resources.qrc
RC_FILE = resource.rc

TRANSLATIONS += \
    widget_zh_CN.ts \
    widget_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
