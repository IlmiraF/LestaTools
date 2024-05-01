#ifndef IMAGEEDITDELEGATE_H
#define IMAGEEDITDELEGATE_H

#include <QItemDelegate>
#include <QFileDialog>
#include <QEvent>

class ImageEditDelegate : public QItemDelegate
{
    Q_OBJECT

    QString file;

public:
    ImageEditDelegate(QObject* parent = nullptr);

protected:
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;

signals:
    void modified() const;
};

#endif // IMAGEEDITDELEGATE_H
