#pragma once

#include <QObject>

class Example : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString type READ GetType)
    Q_PROPERTY(QString name READ GetName WRITE SetName NOTIFY NameChanged)
public:
    Example(QObject* parent = nullptr);
    virtual QString GetName();
    virtual void SetName(const QString& value);

signals:
    void NameChanged(QString);

public slots:
    virtual QString GetType() { return "Example"; } //= 0;

private:
    QString _name = "";
};

class ExampleChild_1 : public Example {
    Q_OBJECT
public:
    ExampleChild_1(QObject* parent = nullptr);
public slots:
    virtual QString GetType() override;
};

class ExampleChild_2 : public Example {
    Q_OBJECT
public:
    ExampleChild_2(QObject* parent = nullptr);
public slots:
    virtual QString GetType() override;
};
