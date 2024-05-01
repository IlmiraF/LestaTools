#ifndef DOUBLESPINBOXDELEGATE_H
#define DOUBLESPINBOXDELEGATE_H

#include <QItemDelegate>
#include <QDoubleSpinBox>

class DoubleSpinBoxDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    DoubleSpinBoxDelegate(QObject* parent = nullptr);

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

#endif // DOUBLESPINBOXDELEGATE_H
