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
            setRightWidget(new VideoFilePreviewWidget(), VIDEO, filePath, fileName);
        } else if (extension::isTextFile(fileExtension)) {
            setRightWidget(new TextPreviewWidget(), TEXT, filePath, fileName);
        } else if (extension::isAudioFile(fileExtension)) {
            // TODO: open audio preview
        }  else if (extension::isImageFile(fileExtension)) {
            setRightWidget(new ImageFilePreviewWidget(), IMAGE, filePath, fileName);
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
    QDebug d(QtMsgType::QtInfoMsg);
    d << "I'm here!";
    auto* w = new NewFileDialog(this, left->model->filePath(left->treeView->currentIndex()));
    w->show();
}

void MainWindow::newFolder() {
    auto response = left->model->mkdir(left->treeView->currentIndex(), "New Folder");
}

void MainWindow::setRightWidget(QWidget *new_right_widget, RIGHT_WIDGET_TYPE type, const QString &file_path, const QString &file_name) {
    delete right;
    right = new_right_widget;

    switch (type) {
        case TEXT: {
            auto *filePreview = dynamic_cast<TextPreviewWidget *>(right);
            filePreview->displayText(file_path, file_name);
            break;
        }
        case IMAGE: {
            auto* image_preview = dynamic_cast<ImageFilePreviewWidget*>(right);
            image_preview->setImage(file_path, file_name);
            break;
        }
        case VIDEO: {
            auto *videoPreview = dynamic_cast<VideoFilePreviewWidget *>(right);
            videoPreview->setCurrentVideo(file_path, file_name);
            break;
        }
        case AUDIO: {
            // TODO: implenet audio display
            break;
        }
    }

    splitter->addWidget(right);
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