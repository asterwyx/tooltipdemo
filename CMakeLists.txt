cmake_minimum_required(VERSION 3.16)

project(tooltipdemo
    VERSION 1.0.0
    LANGUAGES CXX
)

find_package(DtkWidget REQUIRED)

add_executable(tooltipdemo)

target_sources(tooltipdemo PRIVATE
    main.cpp
    mainwindow.hpp
    mainwindow.cpp
    selectormodel.hpp
    selectormodel.cpp
)

target_link_libraries(tooltipdemo PRIVATE Dtk::Widget)
