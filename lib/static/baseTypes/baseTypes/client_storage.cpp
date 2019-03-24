#include "client_storage.h"

#include <QUuid>
#include <QJsonArray>
#include <QJsonObject>

#include <IEventStorage>

ClientStorage::ClientStorage(QObject *parent) : QObject(parent)
{
  auto u = user( QUuid ( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ) );
  u->_lname = tr ( "Шарипов" );
  u->_fname = tr ( "Александр" );
  u->_mname = tr ( "Альфирович" );

  u = user( QUuid ( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 ) );
  u->_lname = tr ( "Звягинцев" );
  u->_fname = tr ( "Александ" );
  u->_mname = tr ( "Владимирович" );

  u = user( QUuid ( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 ) );
  u->_lname = tr ( "Любимов" );
  u->_fname = tr ( "Владимир" );
  u->_mname = tr ( "Геннадьевич" );

  u = user( QUuid ( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 ) );
  u->_lname = tr ( "Зарубин" );
  u->_fname = tr ( "Михаил" );
  u->_mname = tr ( "Михайлович" );
}

ClientStorage::~ClientStorage()
{

}

ClientStorage *ClientStorage::inst()
{
  return instance();
}

ClientStorage *ClientStorage::instance()
{
  static ClientStorage *stor = nullptr;
  if ( !stor )
    stor = new ClientStorage();

  return stor;
}

QUuid ClientStorage::generateUuid()
{
  return QUuid (
        static_cast<uint>( std::rand() )
        , static_cast<ushort>( std::rand() )
        , static_cast<ushort>( std::rand() )
        , static_cast<uchar>( std::rand() )
        , static_cast<uchar>( std::rand() )
        , static_cast<uchar>( std::rand() )
        , static_cast<uchar>( std::rand() )
        , static_cast<uchar>( std::rand() )
        , static_cast<uchar>( std::rand() )
        , static_cast<uchar>( std::rand() )
        , static_cast<uchar>( std::rand() ) );
}

IUser *ClientStorage::user(const QUuid &uid)
{
  if ( !allUsers.contains( uid ) ) {
    auto user = new IUser( this );
    user->_uid = uid;
    allUsers[ uid ] = user;

    emit addedUser( user );
    return user;
  }

  return allUsers[ uid ];
}

QList<IUser *> ClientStorage::allUserList()
{
  return allUsers.values();
}

void ClientStorage::write(const QJsonArray &clientsArray)
{
  QList<std::pair<IUser*, QJsonObject>> toHandle;
  for ( int i = 0; i < clientsArray.count(); ++i ) {
    auto data = clientsArray[ i ].toObject();
    auto u    = user ( QUuid( data[ "uid" ].toString() ) );
    toHandle <<  std::make_pair( u, data );

    u->fromJson( data );
  }

  for ( auto &h: toHandle ) {
    h.first->createdEvents()->fromJson( h.second[ "created" ].toObject() );
  }
}
