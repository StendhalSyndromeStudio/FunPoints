#ifndef IEXTERNAL_RESOURCE_H
#define IEXTERNAL_RESOURCE_H

#include <QObject>
#include "baseTypes/ibase_signal_object.h"

class IExternalResource
    : public IBaseSignalObject
{
  Q_OBJECT
public:
  enum class Type
  {
    Phone, Chat, Link, Video
  };
  Q_ENUM(Type)
protected:
  explicit IExternalResource(QObject *parent = nullptr);
public:
  virtual ~IExternalResource() override;

public slots:
  virtual Type type() const = 0;

signals:

public slots:
};

#endif // IEXTERNAL_RESOURCE_H
