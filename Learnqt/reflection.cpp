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
    //    emit textChange(); //���˵������������Ѿ�����Ҫ�ˡ�
}

void test_testobject()
{
    TestObject* obj = new TestObject;  // newһ������

    qDebug() << obj->objectName() << endl; //������������
    // custom object property
    obj->setProperty("text", "hahaha");    //���ö��������
    qDebug() << obj->property("text").toString() << endl; //������������

    //�õ�ע������Ա����
    qDebug() << "begin--------------------custom class method" << endl;
    const QMetaObject* mobj = obj->metaObject();

    qDebug() << mobj->methodCount() << endl;
    for (int i = 0; i < mobj->methodCount(); i++)
    {
        QMetaMethod mMethod = mobj->method(i);
        QByteArray byteArray = mMethod.name();
        //������������뺯������
        qDebug() << mMethod.typeName() << "->" << QString(byteArray) << endl;
    }
    qDebug() << "end----------------------custom class method" << endl;

    //����ע��ĳ�Ա������ͨ��Q_RETURN_ARG����ȡ����ֵ
    qDebug() << "begin    QMetaObject::invokeMethod" << endl;
    QString invokeString;
    //������ĳ�Ա����
    QMetaObject::invokeMethod(obj, "text", Qt::DirectConnection, Q_RETURN_ARG(QString, invokeString));
    qDebug() << invokeString << endl;
    qDebug() << "end            QMetaObject::invokeMethod" << endl;

    // �ٴ�����textֵ��������Ӧ����źţ����Բο�4
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
