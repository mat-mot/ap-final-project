#include "maplibrary.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    maplibrary w;
    w.show();
    return a.exec();
}
