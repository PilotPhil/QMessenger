#include "qmessenger.h"

QMessenger* QMessenger::m_Instance = nullptr;

QMessenger* QMessenger::getInstance()
{
    if (m_Instance == nullptr)
    {
        m_Instance = new QMessenger();
    }
    return m_Instance;
}

void QMessenger::subscribe(const QString& topic, QObject* obj, const QString& method)
{
    auto todo = ToDo(obj, method);

    if (todoList.contains(topic))
    {
        auto tem = todoList.value(topic);
        tem.append(todo);
        todoList.insert(topic, tem);
    }
    else
    {
        QList<ToDo> l;
        l.append(todo);
        todoList.insert(topic, l);
    }
}

void QMessenger::publish(const QString& topic, const QVariant& msg)
{
    if (todoList.contains(topic))
    {
        auto v = todoList.value(topic);
        for (auto it = v.begin(); it != v.end(); it++)
        {
            auto obj = it->getObj();
            auto tem = it->getMethod().toStdString();

            char* method = const_cast<char*>(tem.c_str());

            QMetaObject::invokeMethod(obj,
                                      method,
                                      Q_ARG(QVariant, msg));
        }
    }
}

void QMessenger::publish(const QString& topic)
{
    if (todoList.contains(topic))
    {
        auto v = todoList.value(topic);
        for (auto it = v.begin(); it != v.end(); it++)
        {
            auto obj = it->getObj();
            auto tem = it->getMethod().toStdString();

            char* method = const_cast<char*>(tem.c_str());

            QMetaObject::invokeMethod(obj,
                                      method);
        }
    }
}

QMessenger::QMessenger()
{

}
