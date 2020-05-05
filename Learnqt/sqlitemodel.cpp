#include "sqlitemodel.h"
#include <qlineedit>
#include <QLayout>
#include <qcoreapplication>
#include <QFileInfo>
#include <qtsql/QSqlRecord>
#include <QCompleter>

SQLiteModelWidget::SQLiteModelWidget(QWidget* p)
    : QWidget(p)
{
    setWindowTitle("sql model");
    setFixedSize(800, 600);

    QString dbname = QCoreApplication::applicationDirPath();
    dbname += "/sqlitemodel.db";
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");;
    database.setDatabaseName(dbname);
    QFileInfo file(dbname);
    if (!file.exists())
    {
        exit(0);
    }
    if (!database.open())
    {
        exit(0);
    }

    tableModel = new QSqlTableModel;
    tableView = new QTableView(this);
    tableModel->setTable("user");
    tableModel->setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);
    
    connect(tableModel, &QSqlTableModel::dataChanged, [=](const QModelIndex& topLeft,
        const QModelIndex& bottomRight,
        const QVector<int>& roles) {
            QStringList strList;
            for (int i = 0; i < tableModel->rowCount(); i++)
            {
                auto record = tableModel->record(i);
                for (int j = 0; j < record.count(); j++)
                {
                    QVariant value = record.value(j);
                    if (value.isNull())
                        continue;
                    strList << value.toString();
                }
            }

            QCompleter* completer = new QCompleter(strList);
            filter->setCompleter(completer);

        });

    tableModel->select();

    tableView->setModel(tableModel);

    auto vboxLay = new QVBoxLayout(this);
    auto hboxLay = new QHBoxLayout(this);

    vboxLay->addLayout(hboxLay);
    vboxLay->addWidget(tableView);

    search = new QLabel(u8"Ìõ¼þ:", this);
    filter = new QLineEdit(this);
    addBtn = new QPushButton("add", this);
    submitBtn = new QPushButton("submit", this);
    resetBtn = new QPushButton("reset", this);
    delBtn = new QPushButton("del", this);

    connect(addBtn, &QPushButton::clicked, [=]() {
        QSqlRecord record = tableModel->record();
        tableModel->insertRecord(-1, record);
        });
    connect(delBtn, &QPushButton::clicked, [=]() {
        });
    connect(resetBtn, &QPushButton::clicked, [=]() {
        //tableModel->;
        });
    connect(submitBtn, &QPushButton::clicked, [=]() {
        tableModel->submitAll();
        });
    connect(filter, &QLineEdit::textChanged, [=](const QString& text) {
        QString s;
        if (!text.isEmpty())
        {
            s = QString("name like '%%1%'").arg(text);
        }
        tableModel->setFilter(s);
        tableModel->select();
        });

    hboxLay->addStretch();
    hboxLay->addWidget(search);
    hboxLay->addWidget(filter);
    hboxLay->addWidget(addBtn);
    hboxLay->addWidget(delBtn);
    hboxLay->addWidget(resetBtn);
    hboxLay->addWidget(submitBtn);
}
