#ifndef IFP_CORE_H
#define IFP_CORE_H

#include <QPointF>

#include "user/iuser.h"
#include "ibase_signal_object.h"
#include "local_event/ilocal_event.h"

class IFpCore
    : public IBaseSignalObject
{
  Q_OBJECT
public:
  struct Filter {
    QPointF     location;
    double      distance;
    QDateTime   start;
    QDateTime   end;
    double      minRate = 0.0;
  };
protected:
  explicit IFpCore(QObject *parent = nullptr);
public:
  virtual ~IFpCore() override;

public slots:
  virtual void isConnected() const = 0;

public slots:
  ///
  /// \brief Текущая позиция
  ///
  virtual QPointF location() const = 0;

  ///
  /// \brief Текущий пользователь
  ///
  virtual IUser *user() const = 0;

public slots:
  virtual QList<ILocalEvent*> getEvents(const Filter &filter) const = 0;

signals:
  void connected();
  void disconnected();

  void userChanged();
  void updateLocation();
};

#endif // IFP_CORE_H
