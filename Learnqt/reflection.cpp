#include "reflection.h"
#include <iostream>
#include <qmetaobject>
#include <qmetatype>
#include <QMetaMethod>

//cpp
TestObject::TestObject(QObject* parent) : QObject(parent)
{
    this->setObjectName("TestObject");
    connect(this, SIGNAL(textChange()), this, SLOT(textslot()));
}
TestObject::~TestObject()
{
}
void TestObject::init()
{
    qDebug() << "*********************";
    qDebug() << "init";
}
QString TestObject::text()
{
    return m_text;
}
void TestObject::setText(const QString& strText)
{
    if (m_text == strText)
        return;
    m_text = strText;
    //    emit textChange(); //有了第四条这个语句已经不需要了。
}

void test_testobject()
{
    TestObject* obj = new TestObject;  // new一个对象

    qDebug() << obj->objectName() << endl; //输出对象的名字
    // custom object property
    obj->setProperty("text", "hahaha");    //设置对象的属性
    qDebug() << obj->property("text").toString() << endl; //输出对象的属性

    //得到注册的类成员函数
    qDebug() << "begin--------------------custom class method" << endl;
    const QMetaObject* mobj = obj->metaObject();

    qDebug() << mobj->methodCount() << endl;
    for (int i = 0; i < mobj->methodCount(); i++)
    {
        QMetaMethod mMethod = mobj->method(i);
        QByteArray byteArray = mMethod.name();
        //输出函数类型与函数名称
        qDebug() << mMethod.typeName() << "->" << QString(byteArray) << endl;
    }
    qDebug() << "end----------------------custom class method" << endl;

    //调用注册的成员函数，通过Q_RETURN_ARG来获取返回值
    qDebug() << "begin    QMetaObject::invokeMethod" << endl;
    QString invokeString;
    //调用类的成员函数
    QMetaObject::invokeMethod(obj, "text", Qt::DirectConnection, Q_RETURN_ARG(QString, invokeString));
    qDebug() << invokeString << endl;
    qDebug() << "end            QMetaObject::invokeMethod" << endl;

    // 再次设置text值，可以响应这个信号，可以参考4
    obj->setProperty("text", "luelueluelue");
}

void test_ReflectionObject()
{   
    ReflectionObject theObject;
    const QMetaObject* theMetaObject = theObject.metaObject();
    auto scanMember = [&]() 
    {
        int methodIndex;
        int methodCount = theMetaObject->methodCount();
        for (methodIndex = 0; methodIndex < methodCount; ++methodIndex)
        {
            QMetaMethod oneMethod = theMetaObject->method(methodIndex);
            qDebug() << "typeName: " << oneMethod.typeName();
            qDebug() << "name: " << oneMethod.name();
            qDebug() << "methodType: " << oneMethod.methodType();;
            qDebug() << "parameterNames: " << oneMethod.parameterNames() << "\n";
        }
    };

    auto scanMemValue = [&]() 
    {
        int propertyIndex;
        int propertyCount = theMetaObject->propertyCount();
        for (propertyIndex = 0; propertyIndex < propertyCount; ++propertyIndex)
        {
            QMetaProperty oneProperty = theMetaObject->property(propertyIndex);
            qDebug() << "name: " << oneProperty.name();
            qDebug() << "type: " << oneProperty.type() << "\n";
        }
    };
    
    auto scanEnum = [&]() 
    {
        int enumeratorIndex;
        int enumeratorCount = theMetaObject->enumeratorCount();
        for (enumeratorIndex = 0; enumeratorIndex < enumeratorCount; ++enumeratorIndex)
        {
            QMetaEnum oneEnumerator = theMetaObject->enumerator(enumeratorIndex);
            int enumIndex;
            int enumCount = oneEnumerator.keyCount();
            for (enumIndex = 0; enumIndex < enumCount; ++enumIndex)
            {
                qDebug() << oneEnumerator.key(enumIndex) << " ==> " << oneEnumerator.value(enumIndex);
            }
        }
    };

    scanMember();
    scanMemValue();
    scanEnum();
}
