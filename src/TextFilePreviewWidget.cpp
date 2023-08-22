//
// Created by Михаил Марков on 15/08/2023.
//

#include "TextFilePreviewWidget.h"

PreviewWidget::PreviewWidget(QWidget *parent)
: QWidget(parent),
grid(new QGridLayout()),
fileName(new QLabel("Click button to show text content!")),
contentPreview(new QTextEdit()){
    initWidgets();
    initLayout();
    initConnections();
}

void PreviewWidget::initLayout() {
    setLayout(grid);

    grid->addWidget(fileName, 0, 0, 1, 1);
    grid->addWidget(contentPreview, 1, 0, 4, 1);
}

void PreviewWidget::initConnections() {

}

void PreviewWidget::initWidgets() {
    fileName->setAlignment(Qt::AlignCenter);
    contentPreview->setReadOnly(true);
}

void PreviewWidget::displayText() {
    contentPreview->clear();
    auto* btnSender = dynamic_cast<QPushButton*>(sender());

    const QString filePath = "/Users/mikhaiil/CLionProjects/FileManger/assets/" + btnSender->text();
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    contentPreview->setText(in.readAll());

    file.close();
}
