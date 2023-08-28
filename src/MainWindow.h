#ifndef FILEMANGER_MAINWINDOW_H
#define FILEMANGER_MAINWINDOW_H

#include "FileTreeWidget.h"
#include "TextFilePreviewWidget.h"
#include "ImageFilePreviewWidget.h"
#include "VideoFilePreviewWidget.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QSplitter>

class MainWindow : public QMainWindow {
Q_OBJECT;
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void initLayout();

    void initConnections();

    void initWidgets();

    void initMenus();

    void initActions();

    QGridLayout *layout;
    QWidget *centralWidget;

    FileTreeWidget *left;
//    PreviewWidget* right;
//    VideoFilePreviewWidget *right;
    QWidget *right;

    QSplitter *splitter;

    QMenu *fileMenu;
    QAction *createFolder;
    QAction *createFile;

private slots:
    void changeRightWidget();

    void newFile();

    void newFolder();
};


#endif //FILEMANGER_MAINWINDOW_H
