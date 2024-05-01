#ifndef DELETECOMMAND_H
#define DELETECOMMAND_H

#include <QUndoCommand>
#include "objectinfo.h"
#include "objectmodel.h"

class DeleteCommand : public QUndoCommand
{
public:
    DeleteCommand(ObjectModel* model, const ObjectInfo& obj);

    void undo() override;
    void redo() override;

private:
    ObjectModel* model;
    ObjectInfo object;
};

#endif // DELETECOMMAND_H
