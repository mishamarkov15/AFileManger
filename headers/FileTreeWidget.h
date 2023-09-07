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

class MyTree : public QTreeView {
    Q_OBJECT;
public:
    void setModel(QAbstractItemModel *model) override {
        QTreeView::setModel(model);
    }

signals:
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected) override;
};

class FileTreeWidget : public QWidget {
Q_OBJECT;
public:
    explicit FileTreeWidget(QWidget *parent = nullptr);

    QString filePath() {
        return model->filePath(treeView->currentIndex());
    }

    QFileSystemModel *model;
    MyTree *treeView;

private:

    void initLayout();
    void initConnections();

    void initWidgets();

    QGridLayout *grid;


};


#endif //FILEMANGER_FILETREEWIDGET_H
