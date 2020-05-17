#pragma once
#include <qstring>
#include <qmetatype>
#include <qobject>
#include <qdebug>

class ReflectionObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int Id READ Id WRITE setId)
    Q_PROPERTY(QString Name READ Name WRITE setName)
    Q_PROPERTY(QString Address READ Address WRITE setAddress)
    Q_PROPERTY(PriorityType Priority READ Priority WRITE setPriority)
    Q_ENUMS(PriorityType)

public:
    enum PriorityType { High, Low, VeryHigh, VeryLow };
    Q_INVOKABLE int Id() { return m_ID; }
    Q_INVOKABLE QString Name() { return m_Name; }
    Q_INVOKABLE QString Address() { return m_Address; }
    Q_INVOKABLE PriorityType Priority() const { return m_Priority; }
    Q_INVOKABLE void setId(const int& id) { m_ID = id; }
    Q_INVOKABLE void setName(const QString& name) { m_Name = name; }
    Q_INVOKABLE void setAddress(const QString& address) { m_Address = address; }
    Q_INVOKABLE void setPriority(PriorityType priority) { m_Priority = priority; }

private:
    int m_ID;
    QString  m_Name;
    QString  m_Address;
    PriorityType m_Priority;
};


//1 .继承 QObject 
class TestObject : public QObject
{
    Q_OBJECT // 2.声明Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChange) //3. Q_PROPERTY 注册成员变量
    Q_PROPERTY(QString text MEMBER m_text NOTIFY textChange) //4. 注册的成员变量能够响应自定义的signals textChange
public:
    TestObject(QObject* parent = nullptr);
    ~TestObject();
    void init();
    //------
    Q_INVOKABLE QString text(); //5.注册类的成员函数
    Q_INVOKABLE void setText(const QString& strText); //5.注册类的成员函数
    QString m_text; //类的成员变量
signals:
    void textChange(); //自定义的signals
public slots:
    void textslot() { qDebug() << "textslot"; } //自定义的signals响应的槽函数
};


void test_testobject();
void test_ReflectionObject();