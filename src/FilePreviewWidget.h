//
// Created by Михаил Марков on 18/08/2023.
//

#ifndef FILEMANGER_FILEPREVIEWWIDGET_H
#define FILEMANGER_FILEPREVIEWWIDGET_H

#include <QWidget>
#include <QGridLayout>

class FilePreviewWidget : public QWidget {
Q_OBJECT;
public:
    explicit FilePreviewWidget(QWidget *parent = nullptr);

protected:

    virtual void initLayout();

    virtual void initConnections();

    virtual void initWidgets();

    QGridLayout *grid;
};


#endif //FILEMANGER_FILEPREVIEWWIDGET_H
