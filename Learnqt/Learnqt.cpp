#include "Learnqt.h"
#include <qmovie>

Learnqt::Learnqt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.actionnew->setIcon(QIcon(":/png/Resources/fb_icon.png"));
    ui.actionopen->setIcon(QIcon(":/png/Resources/fb_icon.png"));

    //ui.piclabel->setPixmap(QPixmap(":/png/Resources/liuhua1.jpg"));
    ui.piclabel->setPixmap(QPixmap(":/png/Resources/logo.png"));
    auto movie = new QMovie(":/png/Resources/liuhua2.gif");
    ui.movieLabel->setMovie(movie);
    movie->start();

    connect(ui.changeBtn, &QPushButton::clicked, [=]() {
        int index = ui.stackedWidget->currentIndex();
        if (index == 0) 
        {
            ui.stackedWidget->setCurrentIndex(1); 
        }
        else if (index == 1)
        {
            ui.stackedWidget->setCurrentIndex(0);
        }
        else 
            ui.stackedWidget->setCurrentIndex(0);


        auto state = movie->state();
        int n = movie->speed();
        if (state == QMovie::MovieState::Paused) 
        {
            movie->setPaused(false);
        }
        else 
        {
            movie->setPaused(true);
        }

        });



}
