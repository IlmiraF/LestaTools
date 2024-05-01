#include "propertyeditwidget.h"

PropertyEditWidget::PropertyEditWidget(QWidget *parent, PropertyModel* new_model)
    : QWidget{parent}, model(new_model)
{
    table = new QTableView(this);
    imageEditDelegate = new ImageEditDelegate(this);
    comboBoxDelegate = new ComboBoxDelegate(this);
    doubleSpinBoxDelegate = new DoubleSpinBoxDelegate(this);
    spinBoxDelegate = new SpinBoxDelegate(this);
    label = new QLabel(this);
    updateImage();

    setMinimumWidth(660);
    setMinimumHeight(100);

    table->setModel(model);
    table->setItemDelegateForColumn(0, imageEditDelegate);
    table->setItemDelegateForColumn(1, comboBoxDelegate);
    table->setItemDelegateForColumn(2, doubleSpinBoxDelegate);
    table->setItemDelegateForColumn(3, spinBoxDelegate);
    table->setFixedWidth(624);

    setLayout(new QVBoxLayout);

    QHBoxLayout* lay = new QHBoxLayout;
    lay->addWidget(label);
    lay->addWidget(table);

    layout()->addItem(lay);

    connect(imageEditDelegate, SIGNAL(modified()), this, SLOT(notify()));
    connect(imageEditDelegate, SIGNAL(modified()), this, SLOT(updateImage()));
    connect(comboBoxDelegate, SIGNAL(modified()), this, SLOT(notify()));
    connect(doubleSpinBoxDelegate, SIGNAL(modified()), this, SLOT(notify()));
    connect(spinBoxDelegate, SIGNAL(modified()), this, SLOT(notify()));
}

void PropertyEditWidget::notify()
{
    emit modified();
}

void PropertyEditWidget::updateImage()
{
    QModelIndex index = model->index(0, 0);
    QPixmap pix(index.data().toString());
    if(!pix.isNull())
    {
        label->setPixmap(pix.scaled(300, 300, Qt::KeepAspectRatio));
    }
}
