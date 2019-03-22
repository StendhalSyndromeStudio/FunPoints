#pragma once
#include <QObject>

class QQmlEngine;
class QJSEngine;

template <class T>
class QmlSingletonProvider
{
//static_assert(std::is_base_of<QObject, T>::value,
//              "T must inherit from QObject");
public:
    virtual ~QmlSingletonProvider() = default;

    static QObject* singletonProvider(QQmlEngine* engine, QJSEngine* scriptEngine)
    {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        T *instance = new T();
        return instance;
    }
};
