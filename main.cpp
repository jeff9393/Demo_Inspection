#include "Demo_Inspection.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Demo_Inspection w;
    w.show();
    return a.exec();
}
