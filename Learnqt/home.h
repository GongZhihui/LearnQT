#pragma once
#include <QtWidgets/QMainWindow>
#include "MetaTypeTest.h"
class HomeMW : public QMainWindow
{
    Q_OBJECT

public:
    HomeMW(QWidget* parent = Q_NULLPTR);

Q_SIGNALS:
    void MetaType(MetaTypeTest mt);
    void MetaTypeReference(const MetaTypeTest &mt);
};