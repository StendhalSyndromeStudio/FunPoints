#ifndef IPERSON_H
#define IPERSON_H

#include <QUuid>
#include "baseTypes/rate/irate_object.h"

class IPerson
    : public QObject
{
  Q_OBJECT
public:
  QUuid         _uid;
  QString       _fname;
  QString       _lname;
  QString       _mname;
  IRateObject   *_rate;
protected:
  explicit IPerson(QObject *parent = nullptr);
  explicit IPerson(const QUuid &uid
                   , const QString &f
                   , const QString &l
                   , const QString &m
                   , QObject *parent = nullptr );
public:
  virtual ~IPerson() override;

public:
  virtual QJsonObject toJson() const;
  virtual void fromJson(const QJsonObject &obj);

public slots:
  IRateObject *rate() const;

public slots:
  virtual QUuid uid() const;
  virtual QString firstName() const;
  virtual QString lastName() const;
  virtual QString patronimic() const;
  virtual QString shortName() const;
};


#endif // IPERSON_H
