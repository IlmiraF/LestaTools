#ifndef COMBOBOXDELEGATE_H
#define COMBOBOXDELEGATE_H

#include <QItemDelegate>
#include <QComboBox>

class ComboBoxDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    ComboBoxDelegate(QObject* parent = nullptr);

protected:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;

signals:
    void modified() const;
};

#endif // COMBOBOXDELEGATE_H
