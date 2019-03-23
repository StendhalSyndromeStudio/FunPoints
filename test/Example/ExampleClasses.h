#pragma once

#include <QObject>

class Example : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString type READ getType CONSTANT)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString name_direct MEMBER _name NOTIFY nameDirectChanged)
public:
    Example(QObject* parent = nullptr);
    virtual QString getName();
    virtual void setName(const QString& value);

signals:
    void nameChanged(QString);
    void nameDirectChanged(QString);
    void testSignal();

public slots:
    virtual QString getType(); //= 0;

private:
    QString _name = "";
};

class ExampleChild_1 : public Example {
    Q_OBJECT
public:
    ExampleChild_1(QObject* parent = nullptr);
public slots:
    virtual QString getType() override;
};

class ExampleChild_2 : public Example {
    Q_OBJECT
public:
    ExampleChild_2(QObject* parent = nullptr);
public slots:
    virtual QString getType() override;
};

class ExampleChild_3 : public Example {
    Q_OBJECT
public:
    ExampleChild_3(QObject* parent = nullptr);
public slots:
    virtual QString getType() override;
};
