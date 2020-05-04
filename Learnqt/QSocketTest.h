#pragma once
#include <QWidget>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/qtcpsocket>

class ClientWidget : public QWidget 
{
public:
    ClientWidget(QWidget* p = nullptr);

    QTcpSocket *socket_;

    bool event(QEvent *ev) override;
};

class ServerWidget : public QWidget 
{
public:
    ServerWidget(QWidget* p = nullptr);

    QTcpServer *server_;
    QTcpSocket *client_;
};