#include "MyLabelWidget.h"
#include <qdebug>
#include <QMouseEvent>

MyLabelWidget::MyLabelWidget(QWidget* parent)
    : QLabel(parent)
{
    //setMouseTracking(true);
}

void MyLabelWidget::enterEvent(QEvent* event)
{
    qDebug() << "enter event";
}

void MyLabelWidget::leaveEvent(QEvent* event)
{
    qDebug() << "leave event";
}

bool MyLabelWidget::event(QEvent* e)
{
    if (e->type() == QEvent::MouseButtonPress)
    {
        auto ev = static_cast<QMouseEvent*>(e);
        if (ev->button() == Qt::MouseButton::LeftButton)
        {
            qDebug() << "left enent mouse press event";
        }
        return true;
    }
    return QLabel::event(e);
}

void MyLabelWidget::mousePressEvent(QMouseEvent* ev)
{
    
}

void MyLabelWidget::mouseReleaseEvent(QMouseEvent* ev)
{
    qDebug() << "mouse release event";
}

void MyLabelWidget::mouseMoveEvent(QMouseEvent* ev)
{
    //if (ev->buttons() & Qt::MouseButton::LeftButton) 
    //{
        QString log = QString(u8"x×ø±ê : %1, y×ø±ê : %2").arg(ev->x()).arg(ev->y());
        qDebug() << "mouse move event" << log.toStdString().c_str();
    //}
}
