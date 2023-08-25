//
// Created by Михаил Марков on 18/08/2023.
//

#include "VideoFilePreviewWidget.h"

VideoFilePreviewWidget::VideoFilePreviewWidget(QWidget *parent)
        : QWidget(parent),
          grid(new QGridLayout()),
          filenameTitle(new QLabel()),
          player(new QMediaPlayer()),
          videoWidget(new QVideoWidget()),
          play_pause(new QPushButton())
          {
    initWidgets();
    initLayout();
    initConnections();
}

void VideoFilePreviewWidget::initLayout() {
    setLayout(grid);

    grid->addWidget(filenameTitle, 0, 0, 1, 1);
    grid->addWidget(videoWidget, 1, 0, 5, 1);
    grid->addWidget(play_pause, 6, 0, 1, 1);
}

void VideoFilePreviewWidget::initConnections() {
    connect(play_pause, &QPushButton::clicked, this, &VideoFilePreviewWidget::playPauseManage);
}

void VideoFilePreviewWidget::initWidgets() {
//    play_pause->setIcon(PLAY_ICON);
    play_pause->setText("play");

    filenameTitle->setAlignment(Qt::AlignCenter);

    player->setVideoOutput(videoWidget);
}

void VideoFilePreviewWidget::playPauseManage() {
    if (player->isPlaying()) {
        player->pause();
//        play_pause->setIcon(PLAY_ICON);
        play_pause->setText("play");
    } else {
        player->play();
//        play_pause->setIcon(PAUSE_ICON);
        play_pause->setText("pause");
    }
}

void VideoFilePreviewWidget::setCurrentVideo(const QString& filePath) {
    player->setSource(QUrl::fromLocalFile(filePath));
}

void VideoFilePreviewWidget::setFilenameTitle(const QString &title) {
    filenameTitle->setText(title);
}

