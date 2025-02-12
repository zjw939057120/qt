cmake_minimum_required(VERSION 3.19)
project(widget LANGUAGES CXX)

include_directories(.)
link_directories(.)

set(CMAKE_PREFIX_PATH "D:/Qt/6.8.2/mingw_64/lib/cmake")
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

qt_standard_project_setup()

qt_add_executable(widget
        WIN32 MACOSX_BUNDLE
        main.cpp
        Utils.cpp
        Toolkit.cpp

        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        aboutdialog.cpp
        aboutdialog.h
        aboutdialog.ui

        faqdialog.cpp
        faqdialog.h
        faqdialog.ui

        manualdialog.cpp
        manualdialog.h
        manualdialog.ui

        methoddialog.cpp
        methoddialog.h
        methoddialog.ui

        queuedialog.cpp
        queuedialog.h
        queuedialog.ui

        queuesettingdialog.cpp
        queuesettingdialog.h
        queuesettingdialog.ui

        recorddialog.cpp
        recorddialog.h
        recorddialog.ui

        revisedialog.cpp
        revisedialog.h
        revisedialog.ui

        sampledialog.cpp
        sampledialog.h
        sampledialog.ui

        resources.qrc
        resource.rc

        modbus.cpp
        socket.cpp
        uart.cpp
        )

qt_add_translations(
        TARGETS widget
        TS_FILES widget_zh_CN.ts
        TS_FILES widget_en_US.ts
)

target_link_libraries(widget
        PRIVATE
        Qt::Core
        Qt::Widgets
        )

target_link_libraries(widget
        PRIVATE
        ws2_32
        Pcomm.lib
        )
include(GNUInstallDirs)

install(TARGETS widget
        BUNDLE DESTINATION .
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )

qt_generate_deploy_app_script(
        TARGET widget
        OUTPUT_SCRIPT deploy_script
        NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
