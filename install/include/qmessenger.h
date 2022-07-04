#ifndef QMESSENGER_H
#define QMESSENGER_H

#include <QObject>
#include <QMap>

#include "todo.h"


class QMessenger : public QObject
{
    Q_OBJECT
public:
    static QMessenger* getInstance();

    /**
     * @brief subscribe
     * @param topic
     * @param obj
     * @param method
     */
    void subscribe(const QString& topic, QObject* obj, const QString& method);


    /**
     * @brief publish
     * @param topic
     * @param msg
     */
    void publish(const QString& topic, const QVariant& msg);

    /**
     * @brief publish
     * @param topic
     * @param msg
     */
    void publish(const QString& topic);


signals:

private:
    QMessenger();

    /**
     * @brief m_Instance 唯一实例指针
     */
    static QMessenger* m_Instance;

    /**
     * @brief dict 话题与调用方法的字典
     */
    QMap<QString, ToDo> dict;

    /**
     * @brief todoList
     */
    QMap<QString, QList<ToDo>> todoList;

};

#endif // QMESSENGER_H
