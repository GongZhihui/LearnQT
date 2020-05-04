#include "QSocketTest.h"
#include <QLayout>
#include <qlineedit>
#include <QPUshButton>
#include <QPUshButton>
#include <QTextEdit>
#include <QTextbrowser>
#include <Qevent>

ClientWidget::ClientWidget(QWidget* p)
    : QWidget(p)
{
    setWindowTitle("client");

    auto hboxLayOut = new QHBoxLayout(this);
    auto lineEdit = new QLineEdit(this);
    auto sendBtn = new QPushButton(u8"·¢ËÍ", this);
    hboxLayOut->addWidget(lineEdit);
    hboxLayOut->addWidget(sendBtn);

    socket_ = new QTcpSocket(this);
    socket_->connectToHost("127.0.0.1", 8099);
    connect(sendBtn, &QPushButton::clicked, [=]() {
        socket_->write(lineEdit->text().toUtf8());
        lineEdit->clear();
        });

    connect(lineEdit, &QLineEdit::returnPressed, [=]() {
        socket_->write(lineEdit->text().toUtf8());
        lineEdit->clear();
        });
}

bool ClientWidget::event(QEvent* ev)
{
    if (ev->type() == QEvent::Close) 
    {
        if (socket_) 
        {
            socket_->close();
        }
        return true;
    }
    return QWidget::event(ev);
}



ServerWidget::ServerWidget(QWidget* p)
    : QWidget(p)
{
    setWindowTitle("server");
    setFixedSize(600, 400);

    auto hboxLayOut = new QVBoxLayout(this);
    auto textEdit = new QTextBrowser(this);
    hboxLayOut->addWidget(textEdit);

    server_ = new QTcpServer;
    server_->listen(QHostAddress::Any, 8099);
    connect(server_, &QTcpServer::newConnection, [=]() {
        while (server_->hasPendingConnections())
        {
            client_ = server_->nextPendingConnection();
            connect(client_, &QTcpSocket::readyRead, [=]() {
                while (client_->bytesAvailable())
                {
                    QByteArray data = client_->readAll();
                    textEdit->append(data);
                }
                });

            connect(client_, &QTcpSocket::connected, [=]() {
                textEdit->append("connect");
                });
            connect(client_, &QTcpSocket::disconnected, [=]() {
                textEdit->append("disconnect");
                });
        }
        
        });
}
