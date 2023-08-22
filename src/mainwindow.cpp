//
// Created by Михаил Марков on 15/08/2023.
//

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent),
          centralWidget(new QWidget()),
          left(new FileTreeWidget(this)),
          right(new VideoFilePreviewWidget(this)),
          layout(new QGridLayout()),
          splitter(new QSplitter()) {
    initWidgets();
    initConnections();
    initLayout();
}

void MainWindow::initLayout() {
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);

    layout->addWidget(splitter);
}

void MainWindow::initConnections() {
    connect(left->treeView, &MyTree::selectionChanged, this, &MainWindow::changeRightWidget);
//    connect(left->btn1, &QPushButton::clicked, right, &PreviewWidget::displayText);
//    connect(left->btn2, &QPushButton::clicked, right, &PreviewWidget::displayText);
//    connect(left->btn3, &QPushButton::clicked, right, &PreviewWidget::displayText);
}

void MainWindow::initWidgets() {
    splitter->addWidget(left);
    splitter->addWidget(right);
}

void MainWindow::changeRightWidget() {
    if (right != nullptr) {
        delete right;
    }
    right = new FilePreviewWidget();
}
