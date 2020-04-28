#include "Learnqt.h"

Learnqt::Learnqt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.actionnew->setIcon(QIcon(":/png/Resources/fb_icon.png"));
    ui.actionopen->setIcon(QIcon(":/png/Resources/fb_icon.png"));
}
