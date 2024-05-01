#include "objectinfo.h"

ObjectInfo::ObjectInfo()
    :name(),
    model(new PropertyModel())
{}

ObjectInfo::ObjectInfo(const QString &str)
    : name(str)
{}

bool ObjectInfo::operator==(const ObjectInfo &other) const
{
    return name == other.name;
}

PropertyModel *ObjectInfo::getModel() const
{
    return model;
}

QString ObjectInfo::toString() const
{
    return name;
}

QString ObjectInfo::getName() const
{
    return name;
}

void ObjectInfo::setName(const QString &newName)
{
    name = newName;
}
