#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include <QListView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

#include <QUndoStack>
#include <QMenu>
#include <QAction>
#include <QMenuBar>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>

#include "objectmodel.h"
#include "propertyeditwidget.h"
#include "addcommand.h"
#include "deletecommand.h"

class MainWindow : public QWidget
{
    Q_OBJECT

    ObjectModel* model;
    QListView* list;
    PropertyEditWidget* property_edit;

    QLineEdit* edit_line;
    QPushButton* add_button;

    QJsonDocument doc;
    QFile file;
    QString globalPath;

    QUndoStack* stack;

    QMenuBar* menuBar;
    QMenu *fileMenu;
    QMenu* commandMenu;
    QAction* deleteObjectAction;
    QAction *openFileAction;
    QAction *saveFileAction;
    QAction *undoAction;
    QAction *redoAction;

public:
    MainWindow(QWidget *parent = nullptr);

private:
    bool isChanged = false;

    void closeEvent(QCloseEvent* event) override;

    void readFile();
    void chooseFile();
    void openNewFile();

public slots:
    void addObject();
    void deleteObject();
    void showObjectProperties(const QModelIndex& index);
    void openFile();
    void saveFile();
    void change();

    void undoCommand();
    void redoCommand();
};
#endif // MAINWINDOW_H
