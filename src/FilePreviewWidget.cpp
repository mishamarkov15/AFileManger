//
// Created by Михаил Марков on 18/08/2023.
//

#include "FilePreviewWidget.h"

FilePreviewWidget::FilePreviewWidget(QWidget *parent) :
        QWidget(parent),
        grid(new QGridLayout()),
        content(new QTextEdit()) {
    initWidgets();
    initLayout();
    initConnections();
}

void FilePreviewWidget::initLayout() {
    setLayout(grid);
    grid->addWidget(content);
}

void FilePreviewWidget::initConnections() {

}

void FilePreviewWidget::initWidgets() {
    content->setReadOnly(true);
}

void FilePreviewWidget::setTextContent(const QString &text) {
    content->setText(text);
}
