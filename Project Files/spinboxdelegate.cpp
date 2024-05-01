#include "spinboxdelegate.h"

SpinBoxDelegate::SpinBoxDelegate(QObject *parent)
    : QItemDelegate{parent}
{}

QWidget *SpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    QSpinBox* box = new QSpinBox(parent);
    return box;
}

void SpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QSpinBox* box = static_cast<QSpinBox*>(editor);
    box->setValue(index.data().toInt());
}

void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox* box = static_cast<QSpinBox*>(editor);
    model->setData(index, box->value());
    emit modified();
}

void SpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index)
    editor->setGeometry(option.rect);
}
