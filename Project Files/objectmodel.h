#ifndef OBJECTMODEL_H
#define OBJECTMODEL_H

#include <QAbstractListModel>
#include <QSet>
#include "objectinfo.h"

class ObjectModel : public QAbstractListModel
{
public:
    explicit ObjectModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent) const;

    void addObject(const ObjectInfo& object);
    void deleteObject(const ObjectInfo& object);

private:
    QSet<ObjectInfo> objects;
};

#endif // OBJECTMODEL_H
