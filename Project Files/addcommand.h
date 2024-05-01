#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include <QUndoCommand>
#include "objectinfo.h"
#include "objectmodel.h"

class AddCommand : public QUndoCommand
{
public:
    AddCommand(ObjectModel* model, const ObjectInfo& obj);

    void undo() override;
    void redo() override;

private:
    ObjectModel* model;
    ObjectInfo object;
};

#endif // ADDCOMMAND_H
