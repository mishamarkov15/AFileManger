//
// Created by Михаил Марков on 15/08/2023.
//

#include "FileTreeWidget.h"
#include "MainWindow.h"

FileTreeWidget::FileTreeWidget(QWidget *parent) :
        QWidget(parent),
        grid(new QGridLayout()),
        model(new QFileSystemModel()),
        view(new QTreeView()) {
    initWidgets();
    initConnections();
    initLayout();
}

void FileTreeWidget::initLayout() {
    setLayout(grid);

    grid->addWidget(view);
}

void FileTreeWidget::initConnections() {

}

void FileTreeWidget::initWidgets() {
    model->setRootPath("");
    view->setModel(model);
    view->setRootIndex(model->index(FOLDER_PATH));
}
