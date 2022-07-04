#include "sender.h"

#include "qmessenger.h"

Sender::Sender(QObject* parent)
    : QObject{parent}
{

}

void Sender::pub()
{
    int a = 1114514;
    QMessenger::getInstance()->publish("topic1", a);
}
