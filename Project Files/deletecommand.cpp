#include "deletecommand.h"

DeleteCommand::DeleteCommand(ObjectModel *model, const ObjectInfo &obj)
    : model(model),
    object(obj)
{}

void DeleteCommand::undo()
{
    model->addObject(object);
}

void DeleteCommand::redo()
{
    model->deleteObject(object);
}
