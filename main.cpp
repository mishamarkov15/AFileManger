#include <QApplication>
#include "src/MainWindow.h"
#include "src/PasswordWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}
