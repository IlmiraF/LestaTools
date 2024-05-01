#ifndef PROPERTYEDITWIDGET_H
#define PROPERTYEDITWIDGET_H

#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>

#include "objectinfo.h"
#include "propertymodel.h"

#include "imageeditdelegate.h"
#include "comboboxdelegate.h"
#include "doublespinboxdelegate.h"
#include "spinboxdelegate.h"

class PropertyEditWidget : public QWidget
{
    Q_OBJECT

    PropertyModel* model;
    QTableView* table;
    QLabel* label;

    ImageEditDelegate* imageEditDelegate;
    ComboBoxDelegate* comboBoxDelegate;
    DoubleSpinBoxDelegate* doubleSpinBoxDelegate;
    SpinBoxDelegate* spinBoxDelegate;

public:
    explicit PropertyEditWidget(QWidget *parent, PropertyModel* model);

signals:
    void modified();

private slots:
    void notify();
    void updateImage();
};

#endif // PROPERTYEDITWIDGET_H
