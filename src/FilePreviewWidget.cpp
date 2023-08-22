//
// Created by Михаил Марков on 18/08/2023.
//

#include "FilePreviewWidget.h"

FilePreviewWidget::FilePreviewWidget(QWidget *parent) :
        QWidget(parent),
        grid(new QGridLayout()) {
    initWidgets();
    initLayout();
    initConnections();
}

void FilePreviewWidget::initLayout() {
    setLayout(grid);
}

void FilePreviewWidget::initConnections() {

}

void FilePreviewWidget::initWidgets() {

}
