#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H


#include <QAbstractTableModel>
#include <QMap>
#include <QVariant>

class CustomTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit CustomTableModel(const QList<QMap<QString, QVariant>> &data, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private:
    QList<QMap<QString, QVariant>> m_data;
};

#endif // CUSTOMTABLEMODEL_H
