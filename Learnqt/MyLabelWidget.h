#pragma once
#include <QtWidgets/QMainWindow>
#include <qlabel>

class MyLabelWidget : public QLabel
{
    Q_OBJECT
public:
    MyLabelWidget(QWidget* parent = Q_NULLPTR);

private:
    void enterEvent(QEvent* event) override;
    void leaveEvent(QEvent* event) override;

    bool event(QEvent *e) override;

    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
};

