#ifndef IRATE_OBJECT_H
#define IRATE_OBJECT_H

#include <QObject>
#include "baseTypes/ibase_signal_object.h"

class IFeedback;

class IRateObject
    : public IBaseSignalObject
{
protected:
  IRateObject(QObject *parrent = nullptr);
public:
  virtual ~IRateObject() override;

public slots:
  virtual double rate() const = 0;
  virtual QList<IFeedback*> feedback() const = 0;

public slots:
  virtual bool addFeedback(IFeedback *feedback) = 0;

signals:
  void changed();
};

#endif // IRATE_OBJECT_H
