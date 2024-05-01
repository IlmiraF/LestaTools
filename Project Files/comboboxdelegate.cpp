#include "comboboxdelegate.h"

ComboBoxDelegate::ComboBoxDelegate(QObject *parent)
    : QItemDelegate{parent}
{}

QWidget *ComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)
    QComboBox* box = new QComboBox(parent);
    QStringList list;
    list << "None" << "Stone" << "Steel" << "Wood";
    box->addItems(list);
    return box;
}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox* box = static_cast<QComboBox*>(editor);
    box->setCurrentText(index.data().toString());
}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox* box = static_cast<QComboBox*>(editor);
    model->setData(index, box->currentText());
    emit modified();
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index)
    editor->setGeometry(option.rect);
}
