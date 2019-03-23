#include "FabricOfExamples.h"
#include "ExampleClasses.h"

FabricOfExamples::FabricOfExamples(QObject *parent) : QObject(parent) {}

FabricOfExamples::~FabricOfExamples() {}

Example *FabricOfExamples::createExampleChild_1() {
    return new ExampleChild_1();
}

Example *FabricOfExamples::createExampleChild_2() {
    return new ExampleChild_2();
}

Example *FabricOfExamples::createExampleChild_3() {
    return new ExampleChild_3();
}
