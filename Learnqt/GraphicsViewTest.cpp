#include "GraphicsViewTest.h"
#include <QGraphicsEllipseItem> 
#include <qgraphicsitem>

MyScene::MyScene(QObject* parent)
    : QGraphicsScene(parent)
{
    drawGirdLine();
}

void MyScene::drawGirdLine()
{
    QPolygonF myPolygon1;
    myPolygon1 << QPointF(0, 10) << QPointF(20, 10);
    QPolygonF myPolygon2;
    myPolygon2 << QPointF(10, 0) << QPointF(10, 20);
    QPixmap pixmap(20, 20);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);

    QVector<qreal> dashes;//line style--ÐéÏß
    qreal space = 2;
    dashes << 2 << space << 2 << space;
    QPen pen(Qt::lightGray, 1);
    pen.setDashPattern(dashes);
    pen.setWidth(1);

    painter.setPen(pen);
    painter.translate(0, 0);
    painter.drawPolyline(myPolygon1);
    painter.drawPolyline(myPolygon2);
    setBackgroundBrush(pixmap);
}


GraphicsViewTest::GraphicsViewTest(QWidget* parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    scene = new MyScene(this);
    ui.graphicsView->setScene(scene);
    ui.graphicsView->setRenderHint(QPainter::Antialiasing);

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);

    QPen blackPen(Qt::black);
    blackPen.setWidth(6);

    connect(scene, &QGraphicsScene::selectionChanged, [=] {
        auto item = scene->focusItem();
        int m = 0;
        });


    ellipse = scene->addEllipse(0, 0, 50,
        100, blackPen, redBrush);
    rectangle = scene->addRect(-100, -100, 50,
        50, blackPen, redBrush);
    myshape = new MyShape;
    scene->addItem(myshape);

    ellipse->setFlags(QGraphicsItem::ItemIsMovable 
        | QGraphicsItem::ItemIsSelectable 
        | QGraphicsItem::ItemIsFocusable   // ¼ü¼üÅÌ½¹µã
    );
    rectangle->setFlags(QGraphicsItem::ItemIsMovable
        | QGraphicsItem::ItemIsSelectable);
    

    connect(ui.pushButton, &QPushButton::clicked, [=]() {
        ellipse->setRotation(10);
        ellipse->setScale(1.5);
        });
}

GraphicsViewTest::~GraphicsViewTest()
{
}

MyShape::MyShape()
{
    setFlags(ItemIsMovable | ItemIsSelectable);
}

QRectF MyShape::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void MyShape::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::blue);
    if (pressed) 
    {
        brush.setColor(Qt::red);
    }
    else 
    {
        brush.setColor(Qt::green);
    }

    painter->fillRect(rec, brush);
    painter->drawEllipse(rec);
    painter->drawRect(rec);
}

void MyShape::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void MyShape::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
