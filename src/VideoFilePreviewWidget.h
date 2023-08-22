//
// Created by Михаил Марков on 18/08/2023.
//

#ifndef FILEMANGER_VIDEOFILEPREVIEWWIDGET_H
#define FILEMANGER_VIDEOFILEPREVIEWWIDGET_H

#include "FilePreviewWidget.h"
#include <QLabel>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>


class VideoFilePreviewWidget : public QWidget {
Q_OBJECT;
public:
    explicit VideoFilePreviewWidget(QWidget *parent = nullptr);

protected:
    void initLayout();

    void initConnections();

    void initWidgets();

private:
    QGridLayout* grid;
    QLabel *filenameTitle;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
};


#endif //FILEMANGER_VIDEOFILEPREVIEWWIDGET_H
