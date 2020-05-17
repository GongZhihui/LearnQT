#include "MetaTypeTest.h"
#include <qvariant>
#include <qdatastream>
#include <qtextstream>
#include <QFile>

MetaTypeTest::MetaTypeTest(const QString& n, const QString& c)
    : name(n)
    , color(c)
    , metaTypeA("typeA")
{
}

QDataStream& operator<<(QDataStream& out, const MetaTypeBase& info)
{
    out << info.base;
    return out;
}

QDataStream& operator>>(QDataStream& out, MetaTypeBase& info)
{
    out >> info.base;
    return out;
}

QDataStream& operator<<(QDataStream& out, const MetaTypeA& info)
{
    out << info.name << static_cast<const MetaTypeBase&>(info);
    return out;
}

QDataStream& operator>>(QDataStream& out, MetaTypeA& info)
{
    out >> info.name >> static_cast<MetaTypeBase&>(info);
    return out;
}

QDataStream& operator<<(QDataStream& out, const MetaTypeTest& info)
{
    out << info.name << info.color << info.metaTypeA;
    return out;
}

QDataStream& operator>>(QDataStream& out, MetaTypeTest& info)
{
    out >> info.name >> info.color >> info.metaTypeA;
    return out;
}

// 自定义类型转为QVariant，然后调用QVariant的save或者load函数保存到文件
void test_meta_type()
{
    // 自定义类型如果要save或load需要调用这个
    qRegisterMetaTypeStreamOperators<MetaTypeTest>("MetaTypeTest");

    int n = qRegisterMetaType<MetaTypeTest>();
    int nnn = QMetaType::type("MetaTypeTest");
    auto typeName = QMetaType::typeName(nnn);

    int qs_size = sizeof(MetaTypeTest);
    MetaTypeTest s{ "color", "name" };

    QFile file("file.dat");
    file.open(QIODevice::ReadWrite);
    QTextStream ts;
    QDataStream ds(&file);
    QDataStream srcs(&file);
    QVariant sv, ssv;
    sv.setValue(s);
    //sv.save(ds);
    //file.flush();
    //file.close();
    ssv.load(ds);
    MetaTypeTest data = ssv.value<MetaTypeTest>();


    int id_s = QMetaTypeId2<MetaTypeTest>::qt_metatype_id();
    QMetaType s_meta_type(id_s);
    int s_size = s_meta_type.sizeOf();
    MetaTypeTest* qs_meta = static_cast<MetaTypeTest*>(s_meta_type.create(&s));
    s_meta_type.destroy(qs_meta);
}

MetaTypeA::MetaTypeA(const QString& a)
    : MetaTypeBase("b1")
    , name(a)
{
}
