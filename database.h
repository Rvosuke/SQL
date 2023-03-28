#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QList>
#include <QMap>
#include <QVariant>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);

    bool connectToDatabase(const QString &host, const int &port,const QString &username, const QString &password, const QString &databaseName);
    bool createTable(const QString &tableName, const QMap<QString, QString> &columns);
    bool insertData(const QString &tableName, const QMap<QString, QVariant> &data);
    bool updateData(const QString& tableName, const QString& condition, const QString& newData);
    bool deleteData(const QString &tableName, const QString &where);
    QList<QMap<QString, QVariant>> queryData(const QString& queryStr);

private:
    QSqlDatabase m_database;
};

#endif // DATABASE_H
