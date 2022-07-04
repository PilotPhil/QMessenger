#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(QObject* parent = nullptr);

    Q_INVOKABLE void doo(const QVariant& data);

    Q_INVOKABLE void doo1(const QVariant& data);

signals:

};

#endif // RECEIVER_H
