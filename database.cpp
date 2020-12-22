#include "database.h"
#include <musicobject.h>

DataBase::DataBase(QObject *parent) : QObject(parent){}
DataBase::~DataBase(){}

void DataBase::connectToDataBase()
{
    if(!QFile("C:/example/" DATABASE_NAME).exists()){
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

bool DataBase::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createTable()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }
    return false;
}

bool DataBase::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("C:/example/" DATABASE_NAME);
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

void DataBase::closeDataBase()
{
    db.close();
}

bool DataBase::createTable()
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " TABLE " ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            TABLE_SONGNAME      " VARCHAR(20)            NOT NULL,"
                            TABLE_SINGERNAME      " VARCHAR(20)            NOT NULL,"
                            TABLE_SINGERSFEAT      " VARCHAR(20)       NOT NULL,"
                            TABLE_SONGLANGUAGE    " VARCHAR(20)          NOT NULL,"
                            TABLE_RELEASEDATE   " VARCHAR(20)     NOT NULL"
                        " )"
                    )){
        qDebug() << "DataBase: error of create " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBase::inserIntoTable(QVector<musicObject> vector, int number)
{
    QSqlQuery query;
    query.prepare("INSERT INTO " TABLE " ( " TABLE_SONGNAME ", "
                                             TABLE_SINGERNAME ", "
                                             TABLE_SINGERSFEAT ", "
                                             TABLE_SONGLANGUAGE ", "
                                             TABLE_RELEASEDATE " ) "
                  "VALUES (:songname, :singername, :singersfeat, :songlanguage, :releasedate )");
    query.bindValue(":songname",        vector[number].get_song_name());
    query.bindValue(":singername",        vector[number].get_singer_name());
    query.bindValue(":singersfeat",      vector[number].get_singers_feat());
    query.bindValue(":songlanguage",     vector[number].get_song_language());
    query.bindValue(":releasedate",     vector[number].get_song_releasedate());
    if(!query.exec()){
        qDebug() << "error insert into " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}
