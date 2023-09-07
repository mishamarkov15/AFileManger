#include "../headers/AudioFilePreview.h"

AudioFilePreviewWidget::AudioFilePreviewWidget(QWidget *parent)
        : QWidget(parent),
          grid(new QGridLayout()),
          filenameTitle(new QLabel()),
          player(new QMediaPlayer()),
          play_pause(new QPushButton()),
          play_next(new QPushButton()),
          play_prev(new QPushButton()),
          audioSlider(new QSlider(Qt::Horizontal)),
          volumeSlider(new QSlider(Qt::Horizontal)),
          PLAY_ICON(QPixmap("../assets/play.png")),
          PAUSE_ICON(QPixmap("../assets/pause.png")),
          audioOutput(new QAudioOutput())
{
    initWidgets();
    initLayout();
    initConnections();
}

void AudioFilePreviewWidget::initLayout() {
    setLayout(grid);

    grid->addWidget(filenameTitle, 0, 0, 1, 4);
    grid->addWidget(play_pause, 1, 1, 1, 1);
    grid->addWidget(play_next, 1, 2, 1, 1);
    grid->addWidget(play_prev, 1, 0, 1, 1);
    grid->addWidget(audioSlider, 1, 3, 1, 2);
    grid->addWidget(volumeSlider, 1, 4, 1, 1);
}

void AudioFilePreviewWidget::initConnections() {
    connect(player, &QMediaPlayer::positionChanged, this, &AudioFilePreviewWidget::updateSlider);
    connect(audioSlider, &QSlider::valueChanged, this, &AudioFilePreviewWidget::setAudioPosition);
    connect(volumeSlider, &QSlider::valueChanged, this, &AudioFilePreviewWidget::setVolume);
    connect(play_pause, &QPushButton::clicked, this, &AudioFilePreviewWidget::playPauseManage);
}

void AudioFilePreviewWidget::initWidgets() {
    play_pause->setIcon(PLAY_ICON);

    filenameTitle->setAlignment(Qt::AlignCenter);

    player->setAudioOutput(audioOutput);

    audioSlider->setMinimum(0);
    audioSlider->setValue(0);
    audioSlider->setMaximum(100);

    volumeSlider->setMinimum(0);
    volumeSlider->setValue(20);
    volumeSlider->setMaximum(100);
}

void AudioFilePreviewWidget::playPauseManage() {
    if (player->isPlaying() == QMediaPlayer::PlayingState) {
        player->pause();
        play_pause->setIcon(PLAY_ICON);
    } else {
        player->play();
        play_pause->setIcon(PAUSE_ICON);
    }
}

void AudioFilePreviewWidget::setCurrentAudio(const QString& filePath, const QString& fileName) {
    filenameTitle->setText(fileName);

    player->setSource(QUrl::fromLocalFile(filePath));
    audioOutput->setMuted(true);
    audioOutput->setVolume(0.2);
}

void AudioFilePreviewWidget::updateSlider() {
    audioSlider->blockSignals(true);
    audioSlider->setValue(static_cast<int>((static_cast<double>(player->position()) / static_cast<double>(player->duration())) * 100.0));
    audioSlider->blockSignals(false);
}

void AudioFilePreviewWidget::setAudioPosition() {
    player->setPosition(static_cast<qint64>(player->duration() * (audioSlider->value() / 100.0)));
}

void AudioFilePreviewWidget::setVolume() {
    if (audioOutput->isMuted()) {
        audioOutput->setMuted(false);
    }

    audioOutput->setVolume(volumeSlider->value() / 100.0);
}
