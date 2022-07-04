#ifndef SENDER_H
#define SENDER_H

#include <QObject>
#include <QVariant>

class Sender : public QObject
{
    Q_OBJECT
public:
    explicit Sender(QObject* parent = nullptr);

    void pub();

signals:

};

#endif // SENDER_H
