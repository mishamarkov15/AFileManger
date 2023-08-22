//
// Created by Михаил Марков on 18/08/2023.
//

#ifndef FILEMANGER_IMAGEFILEPREVIEWWIDGET_H
#define FILEMANGER_IMAGEFILEPREVIEWWIDGET_H

#include "FilePreviewWidget.h"
#include <QLabel>

class ImageFilePreviewWidget : public FilePreviewWidget {
Q_OBJECT;
public:
    explicit ImageFilePreviewWidget(QWidget *parent = nullptr);

protected:
    void initLayout();

    void initConnections();

    void initWidgets();

private:


    QLabel *filenameTitle;
    QLabel *image;
};


#endif //FILEMANGER_IMAGEFILEPREVIEWWIDGET_H
