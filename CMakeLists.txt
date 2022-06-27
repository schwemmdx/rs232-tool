cmake_minimum_required(VERSION 3.1.0)

project(rs232-tool VERSION 0.1.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Charts REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS SerialPort REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Gamepad REQUIRED)

add_executable(rs232-tool
    listentry.cpp
    main.cpp
    mainwindow.cpp
    osziview.cpp
    readingthread.cpp
    settingsdialog.cpp
    writingthread.cpp
    gamepad_dialog.cpp
    listentry.cpp
    gamepadthread.cpp
    loopdialog.cpp
    rs232_ressources.qrc
    loopdialog.ui
    mainwindow.ui
    osziview.ui
    settingsdialog.ui
    gamepad_dialog.ui

)

target_link_libraries(rs232-tool Qt5::Charts)
target_link_libraries(rs232-tool Qt5::Core)
target_link_libraries(rs232-tool Qt5::SerialPort)
target_link_libraries(rs232-tool Qt5::Widgets)
target_link_libraries(rs232-tool Qt5::Gamepad)

#target_link_libraries(rs232-tool yaml-cpp)