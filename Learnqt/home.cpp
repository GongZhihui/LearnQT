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
    setWindowTitle(u8"首页");
    resize(800, 600);

    auto bar = menuBar();
    setMenuBar(bar);
    auto fileMenu = bar->addMenu(u8"文件");
    auto editMenu = bar->addMenu(u8"编辑");

    connect(this, &HomeMW::MetaType, [=](MetaTypeTest mt) {
        QMessageBox::information(this, "tip", mt.color, QMessageBox::Ok);
        });
    connect(this, &HomeMW::MetaType, [=](const MetaTypeTest &mt) {
        QMessageBox::information(this, "tip &", mt.color, QMessageBox::Ok);
        });


    auto saveAction = new QAction(u8"保存", this);
    connect(saveAction, &QAction::triggered, [=]() {
        //QMessageBox::information(this, "tip", "clicked save", QMessageBox::Ok);
        MetaTypeTest mt{"col", "nam"};
        emit MetaType(mt);
        emit MetaTypeReference(mt);

        });


    auto newAction = fileMenu->addAction(u8"新建");
    fileMenu->addSeparator();
    auto openAction = fileMenu->addAction(u8"打开");
    fileMenu->addAction(saveAction);
    editMenu->addAction(saveAction);

    // 工具栏
    auto toolBar = new QToolBar(this);
    addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
    toolBar->setAllowedAreas(Qt::ToolBarArea::TopToolBarArea |
        Qt::ToolBarArea::LeftToolBarArea);

    toolBar->setFloatable(false);
    // 总开关
    toolBar->setMovable(false);

    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);
    toolBar->addSeparator();
    toolBar->addAction(saveAction);

    auto ignoreBtn = new QPushButton(u8"忽略");
    toolBar->addWidget(ignoreBtn);

    // 状态栏
    auto statBar = statusBar();
    setStatusBar(statBar);
    statBar->addWidget(new QLabel(u8"提示信息1", this));
    statBar->addWidget(new QLabel(u8"提示信息2", this));
    statBar->addWidget(new QPushButton(u8"忽略"));

    statBar->addPermanentWidget(new QLabel(u8"右侧提示1", this));
    statBar->addPermanentWidget(new QLabel(u8"右侧提示2", this));
    statBar->addPermanentWidget(new QPushButton(u8"忽略"));

    // 铆接部件
    auto dockWidget = new QDockWidget(u8"浮动", this);
    dockWidget->setAllowedAreas(Qt::DockWidgetArea::LeftDockWidgetArea);
    addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, dockWidget);
    // 设置中心部件
    auto edit = new QTextEdit(this);
    setCentralWidget(edit);

}