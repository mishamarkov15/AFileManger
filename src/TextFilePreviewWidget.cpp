//
// Created by Михаил Марков on 15/08/2023.
//

#include "TextFilePreviewWidget.h"

TextPreviewWidget::TextPreviewWidget(QWidget *parent)
        : QWidget(parent),
          grid(new QGridLayout()),
          filenameLabel(new QLabel()),
          contentPreview(new QTextEdit()) {
    initWidgets();
    initLayout();
    initConnections();
}

void TextPreviewWidget::initLayout() {
    setLayout(grid);

    grid->addWidget(filenameLabel, 0, 0, 1, 1);
    grid->addWidget(contentPreview, 1, 0, 5, 1);
}

void TextPreviewWidget::initConnections() {

}

void TextPreviewWidget::initWidgets() {
    filenameLabel->setAlignment(Qt::AlignCenter);
    contentPreview->setReadOnly(true);
}

void TextPreviewWidget::displayText(const QString& filePath, const QString& fileName) {
    filenameLabel->setText(fileName);

    contentPreview->clear();

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    contentPreview->setText(in.readAll());

    file.close();
}
