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


//1 .�̳� QObject 
class TestObject : public QObject
{
    Q_OBJECT // 2.����Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChange) //3. Q_PROPERTY ע���Ա����
    Q_PROPERTY(QString text MEMBER m_text NOTIFY textChange) //4. ע��ĳ�Ա�����ܹ���Ӧ�Զ����signals textChange
public:
    TestObject(QObject* parent = nullptr);
    ~TestObject();
    void init();
    //------
    Q_INVOKABLE QString text(); //5.ע����ĳ�Ա����
    Q_INVOKABLE void setText(const QString& strText); //5.ע����ĳ�Ա����
    QString m_text; //��ĳ�Ա����
signals:
    void textChange(); //�Զ����signals
public slots:
    void textslot() { qDebug() << "textslot"; } //�Զ����signals��Ӧ�Ĳۺ���
};


void test_testobject();
void test_ReflectionObject();