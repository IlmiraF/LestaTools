#include "imageeditdelegate.h"

ImageEditDelegate::ImageEditDelegate(QObject* parent) : QItemDelegate(parent) {}

bool ImageEditDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    Q_UNUSED(option)
    if(event->type() == QEvent::MouseButtonDblClick)
    {
        file = QFileDialog::getOpenFileName(nullptr, "", "C:\\", "*.png *.jpg");
        model->setData(index, file);
        emit modified();
    }
    return true;
}
