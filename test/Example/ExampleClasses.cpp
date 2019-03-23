#include "ExampleClasses.h"

//class Example

Example::Example(QObject *parent) : QObject(parent) {}

QString Example::getName() {
    return _name;
}

void Example::setName(const QString &value) {
    _name = value;
    emit testSignal();
    emit nameChanged(_name);
}

QString Example::getType() {
    return "Example";
}

//class ExampleChild_1

ExampleChild_1::ExampleChild_1(QObject *parent) : Example(parent) {}

QString ExampleChild_1::getType() {
    return "ExampleChild_1";
}

//class ExampleChild_2

ExampleChild_2::ExampleChild_2(QObject *parent) : Example(parent) {}

QString ExampleChild_2::getType() {
    return "ExampleChild_2";
}

//class ExampleChild_3

ExampleChild_3::ExampleChild_3(QObject *parent) : Example(parent) {}

QString ExampleChild_3::getType() {
    return "ExampleChild_3";
}
