cmake_minimum_required(VERSION 3.16)

project(tooltipdemo
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(DtkWidget REQUIRED)

add_executable(tooltipdemo)

target_sources(tooltipdemo PRIVATE
    main.cpp
    mainwindow.h
    mainwindow.cpp
)

target_link_libraries(tooltipdemo PRIVATE Dtk::Widget)
