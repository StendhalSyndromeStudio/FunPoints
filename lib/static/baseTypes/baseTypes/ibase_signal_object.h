#ifndef IBASE_SIGNAL_OBJECT_H
#define IBASE_SIGNAL_OBJECT_H

#include <QObject>

class IBaseSignalObject : public QObject
{
  Q_OBJECT
protected:
  explicit IBaseSignalObject(QObject *parent = nullptr);
public:
  virtual ~IBaseSignalObject() override;

signals:
  void error(int code, const QString &message);
  void message(const QString &message);
};

#endif // IBASE_SIGNAL_OBJECT_H
