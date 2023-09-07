//
// Created by Михаил Марков on 22/08/2023.
//

#ifndef FILEMANGER_PASSWORDWINDOW_H
#define FILEMANGER_PASSWORDWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class PasswordWindow : public QWidget {
Q_OBJECT;
public:
    explicit PasswordWindow(QWidget* parent = nullptr);
private:
    void initWidgets();
    void initLayout();
    void initConnections();

    QGridLayout* layout;
    QLabel* passwordLabel;
    QLineEdit* passwordInput;
    QPushButton* OK;
private slots:
    bool checkPassword();
};


#endif //FILEMANGER_PASSWORDWINDOW_H
