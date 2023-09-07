cmake_minimum_required(VERSION 3.24)
project(FileManger)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        MultimediaWidgets
        REQUIRED)

add_executable(FileManger main.cpp src/MainWindow.cpp headers/MainWindow.h src/TextFilePreviewWidget.cpp headers/TextFilePreviewWidget.h src/FileTreeWidget.cpp headers/FileTreeWidget.h src/ImageFilePreviewWidget.cpp headers/ImageFilePreviewWidget.h src/PasswordWindow.cpp headers/PasswordWindow.h src/VideoFilePreviewWidget.cpp headers/VideoFilePreviewWidget.h src/dialogs/NewFileDialog.cpp headers/dialogs/NewFileDialog.h
    src/AudioFilePreview.cpp
        headers/AudioFilePreview.h)
target_link_libraries(FileManger
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Multimedia
        Qt::MultimediaWidgets
        )

