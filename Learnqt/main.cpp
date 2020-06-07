#include "Learnqt.h"
#include <QtWidgets/QApplication>
#include "home.h"
#include "testwidget.h"
#include "QSocketTest.h"
#include "sqlitemodel.h"
#include <QtSql/qsqlquery>
#include <QFileInfo>
#include <QtSql/qsqlerror>
#include "MetaTypeTest.h"
#include "reflection.h"
#include <QString>
#include "GraphicsViewTest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //test_ReflectionObject();
    //test_testobject();
    GraphicsViewTest w;
    w.show();
    //test_meta_type();

    /*HomeMW w;
    w.show();

    ServerWidget sw;
    ClientWidget cw;
    sw.show();
    cw.show();
    */
   
    /* MetaTypeTest mt;
    mt.color = "color";
    mt.name = "name";
    QVariant v;
    v.setValue(mt);
    auto mt1 = v.value<MetaTypeTest>();*/


    //SQLiteModelWidget w;
    //w.show();
    return a.exec();
}
