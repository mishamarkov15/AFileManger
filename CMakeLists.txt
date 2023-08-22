cmake_minimum_required(VERSION 3.24)
project(FileManger)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        REQUIRED)

add_executable(FileManger main.cpp src/mainwindow.cpp src/MainWindow.h src/TextFilePreviewWidget.cpp src/TextFilePreviewWidget.h src/FileTreeWidget.cpp src/FileTreeWidget.h src/ImageFilePreviewWidget.cpp src/ImageFilePreviewWidget.h src/FilePreviewWidget.cpp src/FilePreviewWidget.h src/VideoFilePreviewWidget.cpp src/VideoFilePreviewWidget.h)
target_link_libraries(FileManger
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

