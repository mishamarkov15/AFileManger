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

class PreviewWidget : public QWidget {
Q_OBJECT;
public:
    explicit PreviewWidget(QWidget* parent = nullptr);

private:
    void initLayout();
    void initConnections();
    void initWidgets();

    QGridLayout *grid;

    QLabel* fileName;
    QTextEdit* contentPreview;
public slots:
    void displayText();
};


#endif //FILEMANGER_TEXTFILEPREVIEWWIDGET_H
