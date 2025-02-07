cmake_minimum_required(VERSION 3.19)
project(widget LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "D:/Qt/6.8.2/mingw_64/lib/cmake")
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

qt_standard_project_setup()

qt_add_executable(widget
        WIN32 MACOSX_BUNDLE
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        aboutwindow.cpp
        aboutwindow.h
        aboutwindow.ui

        queuesettingwindow.cpp
        queuesettingwindow.h
        queuesettingwindow.ui

        manualwindow.cpp
        manualwindow.h
        manualwindow.ui

        faqwindow.cpp
        faqwindow.h
        faqwindow.ui

        resources.qrc
        resource.rc
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
