#include "testclass.h"
#include <QDebug>

TestClass::TestClass(QObject *parent) : QObject(parent)
{

}

int TestClass::testMethos( ) {
    qDebug( ) << "testMethos";
    return  9;
}
