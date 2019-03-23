#ifndef IFEEDBACK_H
#define IFEEDBACK_H

#include <QUuid>
#include <QDateTime>
#include <QJsonArray>
#include <QJsonObject>
#include "baseTypes/ibase_signal_object.h"

class IPerson;

class IFeedback
    : public IBaseSignalObject
{
  Q_OBJECT
protected:
  QUuid     _uid;
  QString   _title;
  QString   _description;
  QDateTime _publicshed;
  int       _rate;
  mutable IPerson  *_person;
  QList<IFeedback*> _pastList;
public:
  explicit IFeedback(QObject *parent = nullptr);
  explicit IFeedback(const QString &title
                     , const QString &text
                     , int rate
                     , IPerson *person
                     , QObject *parent = nullptr);
  virtual ~IFeedback() override;

public:
  QJsonObject toJson() const;

public slots:
  void fromJson(const QJsonObject &obj);

public slots:
  virtual QUuid uid() const;
  virtual QString title() const;
  virtual QString description() const;
  virtual QDateTime published() const;

  virtual int rate() const;
  virtual IPerson *user() const;
  virtual QList<IFeedback *> pastList() const;

public slots:
  virtual bool edit(const QString &title, const QString &desc, int rate);

signals:
  void changed();
};

#endif // IFEEDBACK_H
