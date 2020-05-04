#include "testwidget.h"
#include <qmovie>
#include <qdebug>
#include <qtimer.h>
#include <qpainter>
#include <QtPrintSupport/qprintpreviewdialog>
#include <QtPrintSupport/qprintdialog>
#include <QtPrintSupport/qprinter.h>

TestWidget::TestWidget(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    timerID1 = startTimer(1000);
    auto timer = new QTimer(this);
    timer->start(1000);
    connect(timer, &QTimer::timeout, [=]() {
        static int i = 0;
        ui.label->setText(QString::number(i++));
        });

    //ui.label->installEventFilter(this);
}

void TestWidget::timerEvent(QTimerEvent* ev)
{
    if (timerID1 == ev->timerId())
    {
        
    }
}

bool TestWidget::eventFilter(QObject* o, QEvent* ev)
{
    return QWidget::eventFilter(o, ev);
}

void TestWidget::paintEvent(QPaintEvent* pe)
{
    QPainter paint(this);
    paint.fillRect(QRect{ 0,0,20,20 }, QColor{255,0,0});
    paint.drawEllipse({100, 100}, 40, 40);
    paint.drawText(100, 200, u8"这是一个文本");
}

void TestWidget::mouseReleaseEvent(QMouseEvent* ev)
{
    if (ev->button() == Qt::MouseButton::RightButton) 
    {
       
    }
}
