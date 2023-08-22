//
// Created by Михаил Марков on 15/08/2023.
//

#include "FileTreeWidget.h"
#include "MainWindow.h"

FileTreeWidget::FileTreeWidget(QWidget *parent) :
        QWidget(parent),
        grid(new QGridLayout()),
        model(new QFileSystemModel()),
        treeView(new MyTree()) {
    initWidgets();
    initConnections();
    initLayout();
}

void FileTreeWidget::initLayout() {
    setLayout(grid);

    grid->addWidget(treeView);
}

void FileTreeWidget::initConnections() {
}

void FileTreeWidget::initWidgets() {
    model->setRootPath("");
    treeView->setModel(model);
    treeView->setRootIndex(model->index(FOLDER_PATH));
}
