#include "ExampleClasses.h"

Example::Example(QObject *parent) : QObject(parent) {}

QString Example::GetName() {
    return _name;
}

void Example::SetName(const QString &value) {
    _name = value;
}

ExampleChild_1::ExampleChild_1(QObject *parent) : Example(parent) {}

QString ExampleChild_1::GetType() {
    return "ExampleChild_1";
}

ExampleChild_2::ExampleChild_2(QObject *parent) : Example(parent) {}

QString ExampleChild_2::GetType() {
    return "ExampleChild_2";
}
