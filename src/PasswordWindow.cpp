//
// Created by Михаил Марков on 22/08/2023.
//

#include "../headers/PasswordWindow.h"

PasswordWindow::PasswordWindow(QWidget *parent) : QDialog(parent),
layout(new QGridLayout()),
passwordLabel(new QLabel()),
passwordInput(new QLineEdit()),
OK(new QPushButton("OK"))
{
    initWidgets();
    initLayout();
    initConnections();
}

void PasswordWindow::initWidgets() {
    passwordLabel->setText("Password");
    passwordInput->setPlaceholderText("Type your password...");

}

void PasswordWindow::initLayout() {
    setLayout(layout);

    layout->addWidget(passwordLabel, 0, 0, 1, 1);
    layout->addWidget(passwordInput, 0, 1, 1, 2);
    layout->addWidget(OK, 1, 2, 1, 1);
}

void PasswordWindow::initConnections() {
    connect(OK, &QPushButton::clicked, this, &PasswordWindow::checkPassword);
}

bool PasswordWindow::checkPassword() {
    if (true) {
        emit(passwordSuccess());
        close();
    }
    return true;
}

