#ifndef IFEEDBACK_H
#define IFEEDBACK_H

#include <QUuid>
#include <QDateTime>
#include "baseTypes/ibase_signal_object.h"

class IPerson;

class IFeedback
    : public IBaseSignalObject
{
  Q_OBJECT
protected:
    explicit IFeedback(QObject *parent = nullptr);
public:
  virtual ~IFeedback() override;

public slots:
  virtual QUuid uid() const = 0;
  virtual QString title() const = 0;
  virtual QString description() const = 0;
  virtual QDateTime published() const = 0;

  virtual int rate() const = 0;
  virtual IPerson *user() const = 0;
  virtual QList<IFeedback*> pastList() const = 0;

public slots:
  virtual void edit(const QString &title, const QString &desc, int rate) = 0;

signals:
  void changed();
};

#endif // IFEEDBACK_H
