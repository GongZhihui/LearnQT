#pragma once
#include <QWidget>
#include <QtSql/qsqltablemodel>
#include <qtableview>
#include <QLineEdit>
#include <qpushbutton>
#include <qlabel>

class SQLiteModelWidget : public QWidget
{
public:
    SQLiteModelWidget(QWidget *p = nullptr);

private:
    QSqlTableModel* tableModel;
    QTableView* tableView;

    QLabel* search;
    QLineEdit* filter;
    QPushButton* addBtn;
    QPushButton* delBtn;
    QPushButton* submitBtn;
    QPushButton* resetBtn;
};

