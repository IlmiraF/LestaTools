#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget{parent}
{
    model = new ObjectModel();
    list = new QListView(this);
    stack = new QUndoStack(this);
    list->setModel(model);

    edit_line = new QLineEdit("", this);
    add_button = new QPushButton("Add Object", this);
    add_button->setShortcut(QKeySequence(Qt::Key_Return));

    QHBoxLayout* lay = new QHBoxLayout;
    lay->addWidget(edit_line);
    lay->addWidget(add_button);

    menuBar = new QMenuBar(this);

    deleteObjectAction = new QAction(tr("&Delete Object"), this);
    deleteObjectAction->setShortcut(tr("Del"));
    connect(deleteObjectAction, SIGNAL(triggered(bool)), this, SLOT(deleteObject()));

    openFileAction = new QAction(tr("&Open File"), this);
    connect(openFileAction, SIGNAL(triggered(bool)), this, SLOT(openFile()));

    saveFileAction = new QAction(tr("&Save File"), this);
    connect(saveFileAction, SIGNAL(triggered(bool)), this, SLOT(saveFile()));

    undoAction = new QAction(tr("&Undo"), this);
    connect(undoAction, SIGNAL(triggered(bool)), this, SLOT(undoCommand()));

    redoAction = new QAction(tr("&Redo"), this);
    connect(redoAction, SIGNAL(triggered(bool)), this, SLOT(redoCommand()));

    fileMenu = menuBar->addMenu(tr("&File"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(saveFileAction);

    commandMenu = menuBar->addMenu(tr("&Command"));
    commandMenu->addAction(undoAction);
    commandMenu->addAction(redoAction);
    commandMenu->addSeparator();
    commandMenu->addAction(deleteObjectAction);

    setMinimumWidth(500);
    setMinimumHeight(500);

    setLayout(new QVBoxLayout);
    layout()->addWidget(menuBar);
    layout()->addWidget(list);
    layout()->addItem(lay);

    file.setFileName(":/output.json");
    readFile();
    file.setFileName("");

    connect(add_button, SIGNAL(clicked(bool)), this, SLOT(addObject()));
    connect(list, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(showObjectProperties(const QModelIndex&)));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(!isChanged)
    {
        event->accept();
    }
    else
    {
        QMessageBox::StandardButton resBtn = QMessageBox::question(this, "Close Editor",
                                                                   tr("Unsaved changes will be lost. Continue?\n"),
                                                                   QMessageBox::No | QMessageBox::Yes,
                                                                   QMessageBox::No);
        if (resBtn == QMessageBox::Yes) {
            event->accept();
        } else {
            event->ignore();
        }
    }
}

void MainWindow::addObject()
{
    if(!edit_line->text().isEmpty())
    {
        ObjectInfo obj;
        obj.setName(edit_line->text());
        model->addObject(obj);
        edit_line->clear();
        change();
        AddCommand* add = new AddCommand(model, obj);
        stack->push(add);
    }
}

void MainWindow::deleteObject()
{
    ObjectInfo info = list->currentIndex().data().value<ObjectInfo>();
    model->deleteObject(info);
    DeleteCommand* delete_com = new DeleteCommand(model, info);
    stack->push(delete_com);
    change();
}

void MainWindow::showObjectProperties(const QModelIndex &index)
{
    ObjectInfo obj = index.data().value<ObjectInfo>();
    property_edit = new PropertyEditWidget(this, obj.getModel());
    property_edit->setWindowTitle(obj.getName());
    property_edit->setAttribute(Qt::WA_DeleteOnClose);
    property_edit->setParent(this, Qt::Window);
    property_edit->show();
    connect(property_edit, SIGNAL(modified()), this, SLOT(change()));
}

void MainWindow::readFile()
{
    if(file.open(QIODevice::ReadOnly))
    {
        QJsonParseError docError;
        doc = QJsonDocument::fromJson(QByteArray(file.readAll()), &docError);
        file.close();

        model = new ObjectModel();

        if(docError.errorString().toInt() == QJsonParseError::NoError)
        {
            QJsonArray docAr = QJsonValue(doc.object().value("objects")).toArray();
            for(int i = 0; i < docAr.count(); ++i)
            {
                ObjectInfo new_obj;
                new_obj.setName(docAr.at(i).toObject().value("name").toString());

                QJsonArray propsArr = QJsonValue(QJsonObject(docAr.at(i).toObject()).value("properties")).toArray();
                for(int j = 0; j < propsArr.count(); ++j)
                {
                    int curr = propsArr.at(j).toObject().value("name").toInt();
                    QVariant value = propsArr.at(j).toObject().value("description").toVariant();
                    QModelIndex index = new_obj.getModel()->index(0,curr);
                    new_obj.getModel()->setData(index, value, 2);
                }

                model->addObject(new_obj);
            }
        }

        ObjectModel *m = static_cast<ObjectModel*>(list->model());
        list->setModel(model);
        m->deleteLater();
    }
}

void MainWindow::chooseFile()
{
    globalPath = QFileDialog::getOpenFileName(nullptr, "", "C:\\", "*.json");
    file.setFileName(globalPath);
}

void MainWindow::openNewFile()
{
    chooseFile();
    readFile();
    stack->clear();
    isChanged = false;
}

void MainWindow::openFile()
{
    if(isChanged)
    {
        QMessageBox::StandardButton resBtn = QMessageBox::question(this, "Open new file",
                                                                   tr("Unsaved changes will be lost. Continue?\n"),
                                                                   QMessageBox::No | QMessageBox::Yes,
                                                                   QMessageBox::No);
        if (resBtn == QMessageBox::Yes) {
            openNewFile();
        }
    }
    else
    {
        openNewFile();
    }
}

void MainWindow::saveFile()
{
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        file.write("{\"objects\":");
        QJsonArray docToWrite = QJsonArray();
        for(int i = 0; i < model->rowCount(QModelIndex()); ++i)
        {
            QModelIndex index = model->index(i, 0);
            ObjectInfo obj = model->data(index).value<ObjectInfo>();
            QVariantMap map;
            map.insert("name", obj.getName());

            QJsonArray properties;
            PropertyModel* property_model = obj.getModel();
            for(int j = 0; j < property_model->columnCount(QModelIndex()); ++j)
            {
                QModelIndex ind = property_model->index(0,j);
                QVariantMap property_map;
                property_map.insert("name", j);
                property_map.insert("description", property_model->data(ind,0));
                QJsonObject json_property = QJsonObject::fromVariantMap(property_map);
                properties.append(json_property);
            }

            map.insert("properties", properties);
            QJsonObject json = QJsonObject::fromVariantMap(map);
            docToWrite.append(json);
        }
        doc.setArray(docToWrite);
        file.write(doc.toJson() + "}");
        file.close();
        isChanged = false;
    }
    else
    {
        chooseFile();
    }
}

void MainWindow::change()
{
    isChanged = true;
}

void MainWindow::undoCommand()
{
    stack->undo();
    change();
}

void MainWindow::redoCommand()
{
    stack->redo();
    change();
}
