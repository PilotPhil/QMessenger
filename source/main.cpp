#include <QCoreApplication>

#include "sender.h"
#include "receiver.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    Receiver r;
    Sender s;

    s.pub();

    return a.exec();
}
