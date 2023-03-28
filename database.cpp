#include "database.h"
#include <QDebug>
#include <QSqlError>

Database::Database(QObject *parent) : QObject(parent)
{
    m_database = QSqlDatabase::addDatabase("QODBC");
}

bool Database::connectToDatabase(const QString &host, const int &port, const QString &username, const QString &password, const QString &databaseName)
{
    m_database.setHostName(host);
    m_database.setPort(port);
    m_database.setUserName(username);
    m_database.setPassword(password);
    m_database.setDatabaseName(databaseName);

    if (m_database.open()) {
        qDebug() << "Connected to the database.";
        return true;
    } else {
        qDebug() << "Failed to connect to the database:" << m_database.lastError().text();
        return false;
    }
}

bool Database::createTable(const QString &tableName, const QMap<QString, QString> &columns)
{
    QSqlQuery query;
    QString queryString = QString("CREATE TABLE %1 (").arg(tableName);

    for (auto it = columns.begin(); it != columns.end(); ++it) {
        queryString.append(QString("%1 %2,").arg(it.key(),it.value()));
    }
    queryString.chop(1);
    queryString.append(")");

    if (query.exec(queryString)) {
        qDebug() << "Table created.";
        return true;
    } else {
        qDebug() << "Failed to create table:" << query.lastError().text();
        return false;
    }
}

bool Database::insertData(const QString &tableName, const QMap<QString, QVariant> &data)
{
    QSqlQuery query;
    QString keys = "(";
    QString values = "(";

    for (auto it = data.begin(); it != data.end(); ++it) {
        keys.append(QString("%1,").arg(it.key()));
        values.append(QString("'%1',").arg(it.value().toString()));
    }
    keys.chop(1);
    values.chop(1);
    keys.append(")");
    values.append(")");

    QString queryString = QString("INSERT INTO %1 (%2) VALUES (%3)").arg(tableName, keys, values);

    if (query.exec(queryString)) {
        qDebug() << "Data inserted.";
        return true;
    } else {
        qDebug() << "Failed to insert data:" << query.lastError().text();
        return false;
    }
}

bool Database::updateData(const QString& tableName, const QString& condition, const QString& newData) {
    QSqlQuery query;
    QString updateQueryStr = QString("UPDATE %1 SET %2 WHERE %3").arg(tableName, newData, condition);

    if (query.exec(updateQueryStr)) {
        qDebug() << "Data updated.";
        return true;
    } else {
        qDebug() << "Failed to update data:" << query.lastError().text();
        return false;
    }
}

bool Database::deleteData(const QString &tableName, const QString &where)
{
    QSqlQuery query;
    QString queryString = QString("DELETE FROM %1").arg(tableName);

    if (!where.isEmpty()) {
        queryString.append(" WHERE " + where);
    }

    if (query.exec(queryString)) {
        qDebug() << "Data deleted.";
        return true;
    } else {
        qDebug() << "Failed to delete data:" << query.lastError().text();
        return false;
    }
}

QList<QMap<QString, QVariant>> Database::queryData(const QString& queryStr) {
    QList<QMap<QString, QVariant>> result;
    QSqlQuery query;
    if (query.exec(queryStr)) {
        QSqlRecord record = query.record();
        int columnCount = record.count();

        while (query.next()) {
            QMap<QString, QVariant> row;
            for (int i = 0; i < columnCount; ++i) {
                row.insert(record.fieldName(i), query.value(i));
            }
            result.append(row);
        }
        qDebug() << "Data queried.";
    } else {
        qDebug() << "Failed to query data:" << query.lastError().text();
    }

    return result;
}
