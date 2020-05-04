#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_testwidget.h"
#include <qlabel>
#include <QMouseEvent>

//---------------------------------------------------

class TestWidget : public QMainWindow
{
    Q_OBJECT

public:
    TestWidget(QWidget* parent = Q_NULLPTR);

private:
    Ui::TestWidget ui;
    int timerID1 = 0;
    void timerEvent(QTimerEvent *ev) override;
    bool eventFilter(QObject *o, QEvent *ev) override;
    void paintEvent(QPaintEvent *pe) override;

    void mouseReleaseEvent(QMouseEvent *ev) override;
};