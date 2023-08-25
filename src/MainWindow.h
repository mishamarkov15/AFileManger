#ifndef FILEMANGER_MAINWINDOW_H
#define FILEMANGER_MAINWINDOW_H

#include "FileTreeWidget.h"
#include "TextFilePreviewWidget.h"
#include "ImageFilePreviewWidget.h"
#include "VideoFilePreviewWidget.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QSplitter>

class MainWindow : public QMainWindow {
Q_OBJECT;
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void initLayout();

    void initConnections();

    void initWidgets();

    QGridLayout *layout;
    QWidget *centralWidget;

    FileTreeWidget *left;
//    PreviewWidget* right;
//    VideoFilePreviewWidget *right;
    QWidget *right;

    QSplitter *splitter;
private slots:
    void changeRightWidget();
};


#endif //FILEMANGER_MAINWINDOW_H
