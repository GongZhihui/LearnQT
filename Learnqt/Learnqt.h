#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Learnqt.h"

class Learnqt : public QMainWindow
{
    Q_OBJECT

public:
    Learnqt(QWidget *parent = Q_NULLPTR);

private:
    Ui::LearnqtClass ui;
};
