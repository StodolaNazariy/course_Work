#ifndef DATABASE_H
#define DATABASE_H
#include <musicobject.h>
#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDebug>

#define DATABASE_HOSTNAME   "ExampleDataBase"
#define DATABASE_NAME       "DataBase.db"
#define TABLE                   "TableExample"
#define TABLE_SONGNAME          "songname"
#define TABLE_SINGERNAME        "singername"
#define TABLE_SINGERSFEAT       "singersfeat"
#define TABLE_SONGLANGUAGE      "songlanguage"
#define TABLE_RELEASEDATE       "releasedate"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();
    void connectToDataBase();
    bool inserIntoTable(QVector<musicObject> vector, int number);

private:
    QSqlDatabase    db;

private:
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();
};

#endif // DATABASE_H
