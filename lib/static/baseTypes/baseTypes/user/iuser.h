#ifndef IUSER_H
#define IUSER_H

#include "iperson.h"

class IEventStorage;

class IUser
    : public IPerson
{
  Q_OBJECT
protected:
  explicit IUser(QObject *parent = nullptr);
public:
  virtual ~IUser() override;

public slots:
  ///
  /// \brief Может ли пользователь создать событие
  ///
  virtual bool canCreateEvent() const = 0;
  virtual IEventStorage *createdEvents() const = 0;
  virtual IEventStorage *visitedEvents() const = 0;
};

#endif // IUSER_H
