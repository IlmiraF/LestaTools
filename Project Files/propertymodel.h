#ifndef PROPERTYMODEL_H
#define PROPERTYMODEL_H

#include <QAbstractTableModel>
#include <QHash>

class PropertyModel : public QAbstractTableModel
{
public:
    explicit PropertyModel(QObject *parent = nullptr);

    int rowCount( const QModelIndex& parent ) const;
    int columnCount( const QModelIndex& parent ) const;
    QVariant data( const QModelIndex& index, int role ) const;
    bool setData( const QModelIndex& index, const QVariant& value, int role );
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const;
    Qt::ItemFlags flags( const QModelIndex& index ) const;

private:
    enum Column {
        ICON = 0,
        MATERIAL,
        SPEED,
        POINTS,
        LAST
    };

    QHash< Column, QVariant > prop_data;
};

#endif // PROPERTYMODEL_H
