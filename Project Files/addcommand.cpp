#include "addcommand.h"

AddCommand::AddCommand(ObjectModel *model, const ObjectInfo &obj)
    : model(model),
    object(obj)
{}

void AddCommand::undo()
{
    model->deleteObject(object);
}

void AddCommand::redo()
{
    model->addObject(object);
}
