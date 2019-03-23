#ifndef FP_CORE_H
#define FP_CORE_H

#include <QObject>

class FpCore : public QObject
{
  Q_OBJECT
public:
  explicit FpCore(QObject *parent = nullptr);

signals:

public slots:
};

#endif // FP_CORE_H