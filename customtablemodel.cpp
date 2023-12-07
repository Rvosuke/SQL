#include "customtablemodel.h"

CustomTableModel::CustomTableModel(const QList<QMap<QString, QVariant>> &data, QObject *parent)
    : QAbstractTableModel(parent), m_data(data)
{
}

int CustomTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.count();
}

int CustomTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    if (!m_data.isEmpty()) {
        return m_data.first().count();
    }
    return 0;
}

QVariant CustomTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    const QMap<QString, QVariant> &row = m_data.at(index.row());
    QString key = row.keys().at(index.column());
    return row.value(key);
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal || m_data.isEmpty()) {
        return QVariant();
    }

    return m_data.first().keys().at(section);
}
