//
// Created by Михаил Марков on 18/08/2023.
//

#include "ImageFilePreviewWidget.h"

ImageFilePreviewWidget::ImageFilePreviewWidget(QWidget *parent) :
        QWidget(parent),
        grid(new QGridLayout()),
        filenameTitle(new QLabel()),
        image(new QLabel()) {
    initWidgets();
    initLayout();
    initConnections();
}

void ImageFilePreviewWidget::initLayout() {
    setLayout(grid);

    grid->addWidget(filenameTitle, 0, 0, 1, 1);
    grid->addWidget(image, 1, 0, 5, 1);
}

void ImageFilePreviewWidget::initConnections() {

}

void ImageFilePreviewWidget::initWidgets() {
    filenameTitle->setAlignment(Qt::AlignCenter);

    image->setAlignment(Qt::AlignCenter);
}

void ImageFilePreviewWidget::setImage(const QString &filePath, const QString& fileName) {
    filenameTitle->setText(fileName);

    image->setPixmap(QPixmap(filePath).scaled(512, 512, Qt::AspectRatioMode::KeepAspectRatio));;
}
