#include "mainwindow.h"

#include <QApplication>
#include "objectinfo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMetaType::registerConverter(&ObjectInfo::toString);

    MainWindow w;
    w.show();
    return a.exec();
}
