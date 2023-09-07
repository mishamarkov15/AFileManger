//
// Created by Михаил Марков on 30/08/2023.
//

#include "../../headers/dialogs/NewFileDialog.h"

NewFileDialog::NewFileDialog(QWidget *parent, const QString &filePath) : QDialog(parent),
                                                                         grid(new QGridLayout()),
                                                                         fileInputLabel(new QLabel()),
                                                                         input(new QLineEdit()),
                                                                         okBtn(new QPushButton()),
                                                                         cancelBtn(new QPushButton()),
                                                                         filePath(filePath) {
    initWidgets();
    initLayout();
    initConnections();
}

void NewFileDialog::initWidgets() {
    setLayout(grid);

    fileInputLabel->setText("Имя файла");
    input->setPlaceholderText("filename...");
    okBtn->setText("Создать");
    cancelBtn->setText("Отмена");
}

void NewFileDialog::initLayout() {
    grid->addWidget(fileInputLabel, 0, 0, 1, 1);
    grid->addWidget(input, 0, 1, 1, 3);
    grid->addWidget(okBtn, 1, 2, 1, 1);
    grid->addWidget(cancelBtn, 1, 3, 1, 1);
}

void NewFileDialog::initConnections() {
    connect(okBtn, &QPushButton::clicked, this, &NewFileDialog::createNewFile);
    connect(cancelBtn, &QPushButton::clicked, this, &NewFileDialog::close);
}

void NewFileDialog::createNewFile() {
    filePath += input->text();

    QString path(filePath);
    QDir dir;

    if (!dir.exists(path)) {
        dir.mkpath(path);
    }
    close();
}

