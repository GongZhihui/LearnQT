#pragma once
#include <qstring>
#include <qmetatype>

class MetaTypeBase 
{
public:
    MetaTypeBase() = default;
    MetaTypeBase(const QString &b) 
        : base(b){}

    friend QDataStream& operator<<(QDataStream& out, const MetaTypeBase& info);
    friend QDataStream& operator>>(QDataStream& out, MetaTypeBase& info);

private:
    QString base;
};

class MetaTypeA : public MetaTypeBase
{
public:
    MetaTypeA() = default;

    MetaTypeA(const QString &a);
    friend QDataStream& operator<<(QDataStream& out, const MetaTypeA& info);
    friend QDataStream& operator>>(QDataStream& out, MetaTypeA& info);

    QString name;
};

class MetaTypeTest
{
    //Q_OBJECT
public:
    MetaTypeTest() = default;
    MetaTypeTest(const QString &n, const QString &c);
    
    friend QDataStream& operator<<(QDataStream& out, const MetaTypeTest &info);
    friend QDataStream& operator>>(QDataStream& out, MetaTypeTest &info);

    MetaTypeA metaTypeA;
    QString name;
    std::shared_ptr<QString> pointer;
    QString color;
};

Q_DECLARE_METATYPE(MetaTypeTest)

void test_meta_type();
