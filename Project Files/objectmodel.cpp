#include "objectmodel.h"

ObjectModel::ObjectModel(QObject *parent)
    : QAbstractListModel{parent}
{}

QVariant ObjectModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
    {
        return QVariant::fromValue(objects.values().at(index.row()));
    }
    return QVariant();
}

int ObjectModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return objects.count();
}

void ObjectModel::addObject(const ObjectInfo &object)
{
    objects.insert(object);
    emit layoutChanged();
}

void ObjectModel::deleteObject(const ObjectInfo &object)
{
    objects.remove(object);
    emit layoutChanged();
}
