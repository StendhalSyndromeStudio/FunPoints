#include "users_storage.h"

UsersStorage::UsersStorage(QObject *parent) : QObject(parent)
{

}

UsersStorage::~UsersStorage()
{

}

IUser *UsersStorage::create(const QString &, const QString , const QString &, bool )
{
  return nullptr;
}
