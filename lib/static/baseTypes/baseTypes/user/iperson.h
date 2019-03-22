#ifndef IPERSON_H
#define IPERSON_H

#include <QUuid>
#include "baseTypes/rate/irate_object.h"

class IPerson
    : public IRateObject
{
  Q_OBJECT
protected:
  explicit IPerson(QObject *parent = nullptr);
public:
  virtual ~IPerson() override;

public slots:
  virtual QUuid uid() const = 0;
  virtual QString firstName() const = 0;
  virtual QString lastName() const = 0;
  virtual QString patronimic() const = 0;
  virtual QString shortName() const = 0;
};


#endif // IPERSON_H
