#ifndef USERS_STORAGE_H
#define USERS_STORAGE_H

#include <IUser>
#include <QObject>

class UsersStorage : public QObject
{
  Q_OBJECT
  QList<IUser*>    users;
public:
  explicit UsersStorage(QObject *parent = nullptr);
  ~UsersStorage() override;

public:
  QList<IUser *> allUsers() const;

public slots:
  IUser *create(const QString &fname, const QString lname, const QString &mname, bool org);

signals:

public slots:
};

#endif // USERS_STORAGE_H
