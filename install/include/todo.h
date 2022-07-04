#ifndef TODO_H
#define TODO_H

#include <QObject>

class ToDo : public QObject
{
    Q_OBJECT
public:
    explicit ToDo(QObject* parent = nullptr);

    ToDo(QObject* _obj, const QString& _method);

    ToDo(const ToDo& other);

    ToDo operator=(const ToDo& other);


    QObject* getObj() const;
    void setObj(QObject* newObj);




    const QString& getMethod() const;
    void setMethod(const QString& newMethod);

signals:

    void objChanged();


    void methodChanged();

private:
    QObject* obj;
    QString method;

    Q_PROPERTY(QObject* obj READ getObj WRITE setObj NOTIFY objChanged)
    Q_PROPERTY(QString method READ getMethod WRITE setMethod NOTIFY methodChanged)
};

Q_DECLARE_METATYPE(ToDo);

#endif // TODO_H
