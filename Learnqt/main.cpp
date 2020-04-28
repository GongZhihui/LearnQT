#include "Learnqt.h"
#include <QtWidgets/QApplication>
#include "home.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //HomeMW w;
    Learnqt w;
    w.show();
    return a.exec();
}
