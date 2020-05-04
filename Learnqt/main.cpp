#include "Learnqt.h"
#include <QtWidgets/QApplication>
#include "home.h"
#include "testwidget.h"
#include "QSocketTest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    ServerWidget sw;
    ClientWidget cw;
    sw.show();
    cw.show();

    return a.exec();
}
