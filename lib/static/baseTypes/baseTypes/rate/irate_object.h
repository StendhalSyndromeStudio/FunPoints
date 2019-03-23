#ifndef IRATE_OBJECT_H
#define IRATE_OBJECT_H

#include <QObject>
#include "ifeedback.h"
#include "baseTypes/ibase_signal_object.h"

class IFeedback;

class IRateObject
    : public IBaseSignalObject
{
  Q_OBJECT
  QList<IFeedback *>    _feedback;
public:
  IRateObject(QObject *parrent = nullptr);
  virtual ~IRateObject() override;

public:
  virtual QJsonObject toJson() const;
  virtual void fromJson(const QJsonObject &obj);


public slots:
  virtual double rate() const;
  virtual QList<IFeedback *> feedback() const;

public slots:
  virtual IFeedback *create(const QString &title, const QString &text, int rate, IPerson *user);
  virtual bool addFeedback(IFeedback *feedback);
  virtual bool removeFeedback(IFeedback *feedback);

signals:
  void addedFeedback(IFeedback *feedback);
  void removedFeedback(IFeedback *feedback);
  void changed();
};

#endif // IRATE_OBJECT_H
