//
// Created by Михаил Марков on 15/08/2023.
//

#ifndef FILEMANGER_FILETREEWIDGET_H
#define FILEMANGER_FILETREEWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTreeWidget>

const QString FOLDER_PATH = "/Users/mikhaiil/.FileManagerData";

class FileTreeWidget : public QWidget {
Q_OBJECT;
public:
    explicit FileTreeWidget(QWidget *parent = nullptr);

private:

    void initLayout();
    void initConnections();

    void initWidgets();

    QGridLayout *grid;

    QFileSystemModel *model;
    QTreeView *view;
};


#endif //FILEMANGER_FILETREEWIDGET_H
