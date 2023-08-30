//
// Created by Михаил Марков on 15/08/2023.
//

#ifndef FILEMANGER_TEXTFILEPREVIEWWIDGET_H
#define FILEMANGER_TEXTFILEPREVIEWWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QDebug>
#include <QFile>
#include <QMessageBox>

class TextPreviewWidget : public QWidget {
Q_OBJECT;
public:
    explicit TextPreviewWidget(QWidget* parent = nullptr);

private:
    void initLayout();
    void initConnections();
    void initWidgets();

    QGridLayout *grid;

    QLabel* filenameLabel;
    QTextEdit* contentPreview;
public:
    void displayText(const QString& filePath, const QString& fileName);
};


#endif //FILEMANGER_TEXTFILEPREVIEWWIDGET_H
