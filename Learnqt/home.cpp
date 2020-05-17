#include "home.h"
#include <qpushbutton.h>
#include <qdebug.h>
#include <qmessagebox.h>
#include <qmenubar>
#include <qtoolbar>
#include <qlabel>
#include <qstatusbar>
#include <qdockwidget>
#include <qtextedit>

HomeMW::HomeMW(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle(u8"��ҳ");
    resize(800, 600);

    auto bar = menuBar();
    setMenuBar(bar);
    auto fileMenu = bar->addMenu(u8"�ļ�");
    auto editMenu = bar->addMenu(u8"�༭");

    connect(this, &HomeMW::MetaType, [=](MetaTypeTest mt) {
        QMessageBox::information(this, "tip", mt.color, QMessageBox::Ok);
        });
    connect(this, &HomeMW::MetaType, [=](const MetaTypeTest &mt) {
        QMessageBox::information(this, "tip &", mt.color, QMessageBox::Ok);
        });


    auto saveAction = new QAction(u8"����", this);
    connect(saveAction, &QAction::triggered, [=]() {
        //QMessageBox::information(this, "tip", "clicked save", QMessageBox::Ok);
        MetaTypeTest mt{"col", "nam"};
        emit MetaType(mt);
        emit MetaTypeReference(mt);

        });


    auto newAction = fileMenu->addAction(u8"�½�");
    fileMenu->addSeparator();
    auto openAction = fileMenu->addAction(u8"��");
    fileMenu->addAction(saveAction);
    editMenu->addAction(saveAction);

    // ������
    auto toolBar = new QToolBar(this);
    addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
    toolBar->setAllowedAreas(Qt::ToolBarArea::TopToolBarArea |
        Qt::ToolBarArea::LeftToolBarArea);

    toolBar->setFloatable(false);
    // �ܿ���
    toolBar->setMovable(false);

    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);
    toolBar->addSeparator();
    toolBar->addAction(saveAction);

    auto ignoreBtn = new QPushButton(u8"����");
    toolBar->addWidget(ignoreBtn);

    // ״̬��
    auto statBar = statusBar();
    setStatusBar(statBar);
    statBar->addWidget(new QLabel(u8"��ʾ��Ϣ1", this));
    statBar->addWidget(new QLabel(u8"��ʾ��Ϣ2", this));
    statBar->addWidget(new QPushButton(u8"����"));

    statBar->addPermanentWidget(new QLabel(u8"�Ҳ���ʾ1", this));
    statBar->addPermanentWidget(new QLabel(u8"�Ҳ���ʾ2", this));
    statBar->addPermanentWidget(new QPushButton(u8"����"));

    // í�Ӳ���
    auto dockWidget = new QDockWidget(u8"����", this);
    dockWidget->setAllowedAreas(Qt::DockWidgetArea::LeftDockWidgetArea);
    addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, dockWidget);
    // �������Ĳ���
    auto edit = new QTextEdit(this);
    setCentralWidget(edit);

}