#include <QApplication>
#include "37_4_1_CalcMainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CalcMainWindow window(nullptr);
    window.show();
    return QApplication::exec();
}
