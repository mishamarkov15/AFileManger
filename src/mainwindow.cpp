//
// Created by Михаил Марков on 15/08/2023.
//

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent),
          centralWidget(new QWidget()),
          left(new FileTreeWidget()),
          right(new QWidget()),
          layout(new QGridLayout()),
          splitter(new QSplitter()) {
    initWidgets();
    initConnections();
    initLayout();
    initActions();
    initMenus();
}

void MainWindow::initLayout() {
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);

    layout->addWidget(splitter);
}

void MainWindow::initConnections() {
    connect(left->treeView, &MyTree::selectionChanged, this, &MainWindow::changeRightWidget);
}

void MainWindow::initWidgets() {
    splitter->addWidget(left);
    splitter->addWidget(right);
}

void MainWindow::changeRightWidget() {
    QDebug d(QtMsgType::QtInfoMsg);
    auto index = left->treeView->currentIndex();
    if (!left->model->isDir(index)) {
        d << "File is not Dir\n";
        auto fileName = left->model->fileName(index);
        d << fileName;
        auto fileExtension = fileName.right(fileName.length() - fileName.lastIndexOf(".") - 1);
        d << fileExtension;
        if (fileExtension == "mp4" || fileExtension == "mov") {
            delete right;
            right = new VideoFilePreviewWidget();

            auto *videoPreview = dynamic_cast<VideoFilePreviewWidget *>(right);
            videoPreview->setCurrentVideo(left->model->filePath(index));
            videoPreview->setFilenameTitle(fileName);

            splitter->addWidget(right);
        } else if (fileExtension == "txt") {
            delete right;
            right = new FilePreviewWidget();

            auto *filePreview = dynamic_cast<FilePreviewWidget *>(right);
            filePreview->setTextContent("Lorem ipsum");

            splitter->addWidget(right);
        }
    }
}

void MainWindow::initMenus() {
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(createFile);
    fileMenu->addAction(createFolder);
}

void MainWindow::initActions() {
    createFile = new QAction("New file", this);
    connect(createFile, &QAction::triggered, this, &MainWindow::newFile);

    createFolder = new QAction("New folder", this);
    connect(createFolder, &QAction::triggered, this, &MainWindow::newFolder);
}

void MainWindow::newFile() {

}

void MainWindow::newFolder() {
    auto response = left->model->mkdir(left->treeView->currentIndex(), "New Folder");
}
