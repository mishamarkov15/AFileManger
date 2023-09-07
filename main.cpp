#include <QApplication>
#include "headers/MainWindow.h"
#include "headers/PasswordWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow w;

    return QApplication::exec();
}
