#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#define DATABASE_HOSTNAME "ExampleDataBase"
#define DATABASE_NAME "DataBase.db"
#define TABLE "TableExample"
#define TABLE_DATE "Date"
#define TABLE_TIME "Time"
#define TABLE_MESSAGE "Message"


class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);

signals:

};

#endif // DATABASE_H
