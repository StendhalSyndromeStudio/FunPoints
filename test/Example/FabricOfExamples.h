#pragma once

#include <QObject>
#include "QmlSingletonProvider.h"

class Example;

class FabricOfExamples : public QObject, public QmlSingletonProvider<FabricOfExamples>
{
    Q_OBJECT
public:
    explicit FabricOfExamples(QObject *parent = nullptr);
    virtual ~FabricOfExamples();
public slots:
    Example* createExampleChild_1();

    Example* createExampleChild_2();

    Example* createExampleChild_3();
};
