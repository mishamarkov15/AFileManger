//
// Created by Михаил Марков on 18/08/2023.
//

#ifndef FILEMANGER_VIDEOFILEPREVIEWWIDGET_H
#define FILEMANGER_VIDEOFILEPREVIEWWIDGET_H

#include "FilePreviewWidget.h"
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>

//const QIcon PLAY_ICON(QPixmap("../assets/play.png"));
//const QIcon PAUSE_ICON(QPixmap("../assets/pause.png"));

class VideoFilePreviewWidget : public QWidget {
Q_OBJECT;
public:
    explicit VideoFilePreviewWidget(QWidget *parent = nullptr);

    void setCurrentVideo(const QString& filePath);

    void setFilenameTitle(const QString& title);

protected:
    void initLayout();

    void initConnections();

    void initWidgets();

private:
    QGridLayout* grid;

    QLabel *filenameTitle;

    QMediaPlayer *player;
    QVideoWidget *videoWidget;

    QPushButton* play_pause;
private slots:
    void playPauseManage();
};


#endif //FILEMANGER_VIDEOFILEPREVIEWWIDGET_H
