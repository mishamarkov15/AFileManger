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
          play_pause(new QPushButton()),
          videoSlider(new QSlider(Qt::Horizontal)),
          volumeSlider(new QSlider(Qt::Horizontal)),
          PLAY_ICON(QPixmap("../assets/play.png")),
          PAUSE_ICON(QPixmap("../assets/pause.png")),
          audioOutput(new QAudioOutput())
          {
    initWidgets();
    initLayout();
    initConnections();
}

void VideoFilePreviewWidget::initLayout() {
    setLayout(grid);

    grid->addWidget(filenameTitle, 0, 0, 1, 7);
    grid->addWidget(videoWidget, 1, 0, 5, 7);
    grid->addWidget(play_pause, 6, 0, 1, 1);
    grid->addWidget(videoSlider, 6, 1, 1, 4);
    grid->addWidget(volumeSlider, 6, 5, 1, 1);
}

void VideoFilePreviewWidget::initConnections() {
    connect(player, &QMediaPlayer::positionChanged, this, &VideoFilePreviewWidget::updateSlider);
    connect(videoSlider, &QSlider::valueChanged, this, &VideoFilePreviewWidget::setVideoPosition);
    connect(volumeSlider, &QSlider::valueChanged, this, &VideoFilePreviewWidget::setVolume);
    connect(play_pause, &QPushButton::clicked, this, &VideoFilePreviewWidget::playPauseManage);
}

void VideoFilePreviewWidget::initWidgets() {
    play_pause->setIcon(PLAY_ICON);

    filenameTitle->setAlignment(Qt::AlignCenter);

    player->setVideoOutput(videoWidget);
    player->setAudioOutput(audioOutput);

    videoSlider->setMinimum(0);
    videoSlider->setValue(0);
    videoSlider->setMaximum(100);

    volumeSlider->setMinimum(0);
    volumeSlider->setValue(20);
    volumeSlider->setMaximum(100);
}

void VideoFilePreviewWidget::playPauseManage() {
    if (player->isPlaying()) {
        player->pause();
        play_pause->setIcon(PLAY_ICON);
    } else {
        player->play();
        play_pause->setIcon(PAUSE_ICON);
    }
}

void VideoFilePreviewWidget::setCurrentVideo(const QString& filePath) {
    player->setSource(QUrl::fromLocalFile(filePath));
    audioOutput->setMuted(true);
    audioOutput->setVolume(0.2);
}

void VideoFilePreviewWidget::setFilenameTitle(const QString &title) {
    filenameTitle->setText(title);
}

void VideoFilePreviewWidget::updateSlider() {
    videoSlider->blockSignals(true);
    videoSlider->setValue(static_cast<int>((static_cast<double>(player->position()) / static_cast<double>(player->duration())) * 100.0));
    videoSlider->blockSignals(false);
}

void VideoFilePreviewWidget::setVideoPosition() {
    player->setPosition(static_cast<qint64>(player->duration() * (videoSlider->value() / 100.0)));
}

void VideoFilePreviewWidget::setVolume() {
    if (audioOutput->isMuted()) {
        audioOutput->setMuted(false);
    }

    audioOutput->setVolume(volumeSlider->value() / 100.);
}

