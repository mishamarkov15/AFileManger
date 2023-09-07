//
// Created by Михаил Марков on 30/08/2023.
//

#ifndef FILEMANGER_NEWFILEDIALOG_H
#define FILEMANGER_NEWFILEDIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDir>
#include <QPushButton>

class NewFileDialog : public QDialog {
Q_OBJECT;
public:
    explicit NewFileDialog(QWidget* parent, QString  filePath);

public slots:
    void createNewFile();

private:
    void initWidgets();

    void initLayout();

    void initConnections();

    QGridLayout* grid;
    QLabel* fileInputLabel;
    QLineEdit* input;
    QPushButton* okBtn;
    QPushButton* cancelBtn;
    QString filePath;
};


#endif //FILEMANGER_NEWFILEDIALOG_H
