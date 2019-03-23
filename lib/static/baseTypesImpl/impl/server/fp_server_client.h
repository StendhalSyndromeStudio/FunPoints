#ifndef FP_SERVER_CLIENT_H
#define FP_SERVER_CLIENT_H

#include <QObject>

class FpServerClient : public QObject
{
  Q_OBJECT
public:
  explicit FpServerClient(QObject *parent = nullptr);
  ~FpServerClient() override;
signals:

public slots:
};

#endif // FP_SERVER_CLIENT_H
