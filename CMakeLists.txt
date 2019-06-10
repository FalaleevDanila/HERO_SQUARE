cmake_minimum_required(VERSION 3.14)
project(HERO_SQUARE)

set(CMAKE_CXX_STANDARD 14)

find_package(
        Qt5
        HINTS "$ENV{QTDIR}"
        REQUIRED COMPONENTS
        Core
        Widgets
)

include_directories(HERO_SQUARE)

add_executable(HERO_SQUARE
        HERO_SQUARE/body.cpp
        HERO_SQUARE/body.h
        HERO_SQUARE/gamewindow.cpp
        HERO_SQUARE/gamewindow.h
        HERO_SQUARE/gamewindow.ui
        HERO_SQUARE/HERO_SQUARE.pro
        HERO_SQUARE/HERO_SQUARE.pro.user
        HERO_SQUARE/main.cpp
        HERO_SQUARE/mainwindow.cpp
        HERO_SQUARE/mainwindow.h
        HERO_SQUARE/mainwindow.ui
        HERO_SQUARE/pausewindow.cpp
        HERO_SQUARE/pausewindow.h
        HERO_SQUARE/pausewindow.ui
        HERO_SQUARE/trainingwindow.cpp
        HERO_SQUARE/trainingwindow.h
        HERO_SQUARE/trainingwindow.ui
        HERO_SQUARE/widget.cpp
        HERO_SQUARE/widget.h
        HERO_SQUARE/widget.ui)

set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC TRUE)
set_target_properties(${PROJECT_NAME} PROPERTIES AUTOUIC TRUE)
set_target_properties(${PROJECT_NAME} PROPERTIES AUTORCC TRUE)

target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core Qt5::Widgets)

