//
// Created by Михаил Марков on 18/08/2023.
//

#include "VideoFilePreviewWidget.h"

VideoFilePreviewWidget::VideoFilePreviewWidget(QWidget *parent)
        : QWidget(parent),
          grid(new QGridLayout()),
          filenameTitle(new QLabel()),
          player(new QMediaPlayer()),
          videoWidget(new QVideoWidget())
          {
    initWidgets();
    initLayout();
    initConnections();
}

void VideoFilePreviewWidget::initLayout() {
    setLayout(grid);

    grid->addWidget(filenameTitle, 0, 0, 1, 1);
//    grid->addWidget(videoWidget, 1, 0, 5, 1);
}

void VideoFilePreviewWidget::initConnections() {
}

void VideoFilePreviewWidget::initWidgets() {
//    player->setSource(QUrl::fromLocalFile("/Users/mikhaiil/Documents/C++ Знакомство.mp4"));
//    player->setVideoOutput(videoWidget);
}
