#ifndef OBJECTINFO_H
#define OBJECTINFO_H

#include <QMetaType>
#include <QString>
#include <QDebug>
#include "propertymodel.h"

class ObjectInfo
{
public:
    ObjectInfo();

    ObjectInfo(const QString& str);

    bool operator==(const ObjectInfo &other) const;

    PropertyModel *getModel() const;

    QString toString() const;

    QString getName() const;
    void setName(const QString &newName);

private:
    QString name;
    PropertyModel* model;
};

inline uint qHash(const ObjectInfo &key, uint seed){
    return qHash(key.getName(), seed) ^ qHash(key.getName(), seed + 1);
}

Q_DECLARE_METATYPE(ObjectInfo)

#endif // OBJECTINFO_H
