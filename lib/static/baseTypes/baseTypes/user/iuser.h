#ifndef IUSER_H
#define IUSER_H

#include "iperson.h"

class IEventStorage;

class IUser
    : public IPerson
{
  Q_OBJECT
  IEventStorage   *created;
  IEventStorage   *visited;
public:
  explicit IUser(QObject *parent = nullptr);
  virtual ~IUser() override;

public slots:
  ///
  /// \brief Может ли пользователь создать событие
  ///
  virtual bool canCreateEvent() const;
  virtual IEventStorage *createdEvents() const;
  virtual IEventStorage *visitedEvents() const;
};

#endif // IUSER_H
