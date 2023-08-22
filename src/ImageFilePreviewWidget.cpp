//
// Created by Михаил Марков on 18/08/2023.
//

#include "ImageFilePreviewWidget.h"

ImageFilePreviewWidget::ImageFilePreviewWidget(QWidget *parent) :
        FilePreviewWidget(parent),
        filenameTitle(new QLabel("photo.png")),
        image(new QLabel()) {
    initWidgets();
    initLayout();
    initConnections();
}

void ImageFilePreviewWidget::initLayout() {
    FilePreviewWidget::initLayout();

    grid->addWidget(filenameTitle, 0, 0, 1, 1);
    grid->addWidget(image, 1, 0, 5, 1);
}

void ImageFilePreviewWidget::initConnections() {
    FilePreviewWidget::initConnections();
}

void ImageFilePreviewWidget::initWidgets() {
    FilePreviewWidget::initWidgets();

    filenameTitle->setAlignment(Qt::AlignCenter);

    image->setAlignment(Qt::AlignCenter);
    image->setPixmap(QPixmap("/Users/mikhaiil/CLionProjects/FileManger/assets/cpp_logo.png").scaled(128, 128, Qt::AspectRatioMode::KeepAspectRatio));
}
