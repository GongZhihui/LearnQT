#pragma once

#include <QDialog>
#include "ui_graphics_view.h"
#include <qgraphicsview>
#include <qgraphicsscene>
#include <qgraphicsitem>

class MyScene : public QGraphicsScene 
{
    Q_OBJECT
public:
    MyScene(QObject *parent = nullptr);
    void drawGirdLine();
};

class MyShape : public QGraphicsItem 
{
public:
    MyShape();
    QRectF boundingRect() const override;
    void paint(QPainter* painter, 
        const QStyleOptionGraphicsItem* option, 
        QWidget* widget = nullptr) override;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
    bool pressed = false;
};

class GraphicsViewTest : public QDialog
{
    Q_OBJECT

public:
    GraphicsViewTest(QWidget *parent = nullptr);
    ~GraphicsViewTest();


private:
    Ui_Form ui;
    MyScene* scene;
    QGraphicsEllipseItem* ellipse;
    QGraphicsRectItem* rectangle;
    MyShape* myshape;
    QGraphicsPathItem* path;
};
