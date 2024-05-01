#include "doublespinboxdelegate.h"

DoubleSpinBoxDelegate::DoubleSpinBoxDelegate(QObject *parent)
    : QItemDelegate{parent}
{}

QWidget *DoubleSpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)
    QDoubleSpinBox* box = new QDoubleSpinBox(parent);
    return box;
}

void DoubleSpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QDoubleSpinBox* box = static_cast<QDoubleSpinBox*>(editor);
    box->setValue(index.data().toDouble());
}

void DoubleSpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDoubleSpinBox* box = static_cast<QDoubleSpinBox*>(editor);
    model->setData(index, box->value());
    emit modified();
}

void DoubleSpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index)
    editor->setGeometry(option.rect);
}
