#include <QApplication>
#include "TV_Control.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    TV_Control window(nullptr);
    window.show();
    return QApplication::exec();
}
