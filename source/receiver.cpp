#include "receiver.h"

#include "qmessenger.h"
#include <QDebug>

Receiver::Receiver(QObject* parent)
    : QObject{parent}
{
    QMessenger::getInstance()->subscribe("topic1", this, "doo");
    QMessenger::getInstance()->subscribe("topic1", this, "doo1");
}

void Receiver::doo(const QVariant& data)
{
    qDebug() << data.toInt();
}

void Receiver::doo1(const QVariant& data)
{
    qDebug() << "doo1: " << data.toInt();
}
