//
// Created by Михаил Марков on 18/08/2023.
//

#ifndef FILEMANGER_VIDEOFILEPREVIEWWIDGET_H
#define FILEMANGER_VIDEOFILEPREVIEWWIDGET_H

#include "FilePreviewWidget.h"
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QSlider>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtMultimedia/QAudioOutput>

class VideoFilePreviewWidget : public QWidget {
Q_OBJECT;
public:
    explicit VideoFilePreviewWidget(QWidget *parent = nullptr);

    void setCurrentVideo(const QString &filePath, const QString &fileName);


protected:
    void initLayout();

    void initConnections();

    void initWidgets();

private:
    QGridLayout *grid;

    QLabel *filenameTitle;

    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QAudioOutput *audioOutput;
    QSlider *videoSlider;
    QSlider *volumeSlider;

    QPushButton *play_pause;

    const QIcon PLAY_ICON;
    const QIcon PAUSE_ICON;
private slots:

    void playPauseManage();

    void updateSlider();

    void setVideoPosition();

    void setVolume();
};


#endif //FILEMANGER_VIDEOFILEPREVIEWWIDGET_H
