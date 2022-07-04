#include "todo.h"

ToDo::ToDo(QObject* parent)
    : QObject{parent}
{

}

ToDo::ToDo(QObject* _obj, const QString& _method)
{
    obj = _obj;
    method = _method;
}

ToDo::ToDo(const ToDo& other)
{
    obj = other.obj;
    method = other.method;
}

ToDo ToDo::operator=(const ToDo& other)
{
    return other;
}

QObject* ToDo::getObj() const
{
    return obj;
}

void ToDo::setObj(QObject* newObj)
{
    if (obj == newObj)
        return;
    obj = newObj;
    emit objChanged();
}

const QString& ToDo::getMethod() const
{
    return method;
}

void ToDo::setMethod(const QString& newMethod)
{
    if (method == newMethod)
        return;
    method = newMethod;
    emit methodChanged();
}



