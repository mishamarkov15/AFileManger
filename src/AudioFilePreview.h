#ifndef AUDIOFILEPREVIEWWIDGET_H
#define AUDIOFILEPREVIEWWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QMediaPlayer>
#include <QPushButton>
#include <QSlider>
#include <QAudioOutput>

class AudioFilePreviewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AudioFilePreviewWidget(QWidget *parent = nullptr);

    void setCurrentAudio(const QString& filePath, const QString& fileName);

private slots:
    void playPauseManage();
    void updateSlider();
    void setAudioPosition();
    void setVolume();

private:
    void initLayout();
    void initConnections();
    void initWidgets();

    QGridLayout *grid;
    QLabel *filenameTitle;
    QMediaPlayer *player;
    QPushButton *play_pause, *play_next, *play_prev;
    QSlider *audioSlider;
    QSlider *volumeSlider;
    QPixmap PLAY_ICON;
    QPixmap PAUSE_ICON;
    QAudioOutput *audioOutput;
};

#endif // AUDIOFILEPREVIEWWIDGET_H
