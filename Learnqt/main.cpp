#include "Learnqt.h"
#include <QtWidgets/QApplication>
#include "home.h"
#include "testwidget.h"
#include "QSocketTest.h"
#include "sqlitemodel.h"
#include <QtSql/qsqlquery>
#include <QFileInfo>
#include <QtSql/qsqlerror>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    /*ServerWidget sw;
    ClientWidget cw;
    sw.show();
    cw.show();
    */
    

    SQLiteModelWidget w;
    w.show();
    return a.exec();
}
