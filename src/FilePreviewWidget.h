//
// Created by Михаил Марков on 18/08/2023.
//

#ifndef FILEMANGER_FILEPREVIEWWIDGET_H
#define FILEMANGER_FILEPREVIEWWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QTextEdit>

class FilePreviewWidget : public QWidget {
Q_OBJECT;
public:
    explicit FilePreviewWidget(QWidget *parent = nullptr);

    void setTextContent(const QString& text);

protected:

    void initLayout();

    void initConnections();

    void initWidgets();

    QGridLayout *grid;

    QTextEdit *content;
};


#endif //FILEMANGER_FILEPREVIEWWIDGET_H
