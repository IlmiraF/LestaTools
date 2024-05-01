#include "propertymodel.h"

PropertyModel::PropertyModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    prop_data[ICON] = ":/scale_1200.jpg";
    prop_data[MATERIAL] = "None";
    prop_data[SPEED] = 0.0f;
    prop_data[POINTS] = 0;
}

int PropertyModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 1;
}

int PropertyModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return LAST;
}

QVariant PropertyModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() ||
        prop_data.count() <= index.row() ||
        ( role != Qt::DisplayRole && role != Qt::EditRole ))
    {
        return QVariant();
    }
    return prop_data[Column(index.column())];
}

bool PropertyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if( !index.isValid() || role != Qt::EditRole) {
        return false;
    }

    prop_data[ Column( index.column() ) ] = value;
    emit dataChanged( index, index );

    return true;
}

QVariant PropertyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if( role != Qt::DisplayRole ) {
        return QVariant();
    }

    if( orientation == Qt::Vertical ) {
        return section;
    }

    switch( section ) {
    case ICON:
        return QString("Image");
    case MATERIAL:
        return QString("Material");
    case SPEED:
        return QString("Speed");
    case POINTS:
        return QString("Points");
    }

    return QVariant();
}

Qt::ItemFlags PropertyModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );
    if( index.isValid() ) {
        flags |= Qt::ItemIsEditable;
    }

    return flags;
}
