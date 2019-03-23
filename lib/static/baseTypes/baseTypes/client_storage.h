#ifndef CLIENT_STORAGE_H
#define CLIENT_STORAGE_H

#include <QMap>
#include <IUser>
#include <QObject>

class ClientStorage : public QObject
{
  Q_OBJECT
  QMap<QUuid, IUser *>  allUsers;
  explicit ClientStorage(QObject *parent = nullptr);
public:
  ~ClientStorage() override;

public:
  static ClientStorage *inst();
  static ClientStorage *instance();

public slots:
  IUser *user(const QUuid &uid);
  QList<IUser*> allUserList();
  void write(const QJsonArray &clientsArray);

signals:
  void addedUser(IUser *user) ;
};

#endif // CLIENT_STORAGE_H
