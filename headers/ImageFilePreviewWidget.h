//
// Created by Михаил Марков on 18/08/2023.
//

#ifndef FILEMANGER_IMAGEFILEPREVIEWWIDGET_H
#define FILEMANGER_IMAGEFILEPREVIEWWIDGET_H

#include <QLabel>
#include <QGridLayout>

class ImageFilePreviewWidget : public QWidget {
Q_OBJECT;
public:
    explicit ImageFilePreviewWidget(QWidget *parent = nullptr);

protected:
    void initLayout();

    void initConnections();

    void initWidgets();

public:
    void setImage(const QString& filePath, const QString& fileName);

private:
    QGridLayout *grid;

    QLabel *filenameTitle;
    QLabel *image;
};


#endif //FILEMANGER_IMAGEFILEPREVIEWWIDGET_H
