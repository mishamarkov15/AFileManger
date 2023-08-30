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
        auto filePath = left->model->filePath(index);
        auto fileName = left->model->fileName(index);
        auto fileExtension = fileName.right(fileName.length() - fileName.lastIndexOf(".") - 1);
        if (extension::isVideoFile(fileExtension)) {
            delete right;
            right = new VideoFilePreviewWidget();

            auto *videoPreview = dynamic_cast<VideoFilePreviewWidget *>(right);
            videoPreview->setCurrentVideo(left->model->filePath(index));
            videoPreview->setFilenameTitle(fileName);

            splitter->addWidget(right);
        } else if (extension::isTextFile(fileExtension)) {
            delete right;
            right = new FilePreviewWidget();

            auto *filePreview = dynamic_cast<FilePreviewWidget *>(right);
            filePreview->setTextContent("Lorem ipsum");

            splitter->addWidget(right);
        } else if (extension::isAudioFile(fileExtension)) {
            // TODO: open audio preview
        }  else if (extension::isImageFile(fileExtension)) {
            delete right;
            right = new ImageFilePreviewWidget();

            auto* image_preview = dynamic_cast<ImageFilePreviewWidget*>(right);
            image_preview->setImage(filePath, fileName);
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

inline bool extension::isTextFile(const QString &file_extension) {
    return extension::TEXT_EXTENSIONS.contains(file_extension.toLower());
}

inline bool extension::isAudioFile(const QString &file_extension) {
    return extension::AUDIO_EXTENSIONS.contains(file_extension.toLower());
}

inline bool extension::isVideoFile(const QString &file_extension) {
    return extension::VIDEO_EXTENSIONS.contains(file_extension.toLower());
}

inline bool extension::isImageFile(const QString &file_extension) {
    return extension::IMAGE_EXTENSIONS.contains(file_extension.toLower());
}