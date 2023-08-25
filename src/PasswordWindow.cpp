//
// Created by Михаил Марков on 22/08/2023.
//

#include "PasswordWindow.h"

PasswordWindow::PasswordWindow(QWidget *parent) : QWidget(parent),
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
    layout->addWidget(passwordLabel, 0, 0, 1, 1);
    layout->addWidget(passwordInput, 0, 1, 1, 2);
    layout->addWidget(OK, 1, 2, 1, 1);
}

void PasswordWindow::initConnections() {
    connect(OK, &QPushButton::clicked, this, &PasswordWindow::checkPassword);
}

bool PasswordWindow::checkPassword() {
    if (true) {
        close();
    }
}