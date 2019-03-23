#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <QObject>
#include <QDateTime>
#include <QTcpSocket>
#include <QHostAddress>

class TcpClient
    : public QObject
{
  Q_OBJECT
  QTcpSocket    *_socket;
  QByteArray    buffer;
  QHostAddress  address;
  quint16       port;
  bool          reconnect;
  QDateTime     lastTryConnect;
public:
  explicit TcpClient(QObject *parent = nullptr);
  explicit TcpClient(QTcpSocket *socket, QObject *parent = nullptr);
  ~TcpClient() override;

  // QObject interface
protected:
  void timerEvent(QTimerEvent *event) override;

public:
  QTcpSocket *socket() const;
  bool isConnected() const;

public slots:
  void connectToHost(const QHostAddress &address, quint16 port);
  void close();
  int write(const QByteArray &data);

signals:
  void connected();
  void disconnected();
  void incommingMessage(const QByteArray &data);

private:
  void connectSocket();

private slots:
  void readyReadPrivate();
  void connectedToServer();
  void disconnectedFromServer();

};

#endif // TCP_CLIENT_H
