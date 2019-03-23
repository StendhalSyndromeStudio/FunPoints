#ifndef LOCAL_EVENT_LIST_MODEL_H
#define LOCAL_EVENT_LIST_MODEL_H

#include "ilocal_event.h"
#include <QModelIndex>
#include <QAbstractListModel>

class LocalEventListModel
    : public QAbstractListModel
{
  Q_OBJECT
public:
  QList<ILocalEvent*>     allEvents;
public:
  explicit LocalEventListModel(QObject *parent = nullptr);
  ~LocalEventListModel() override;

  // QAbstractItemModel interface
public:
  int rowCount(const QModelIndex &parent) const override;
  QVariant data(const QModelIndex &index, int role) const override;

public slots:
  Q_INVOKABLE void addEvent(ILocalEvent *event)
  {
    allEvents.append( event );
    endInsertRows( );
  }
  ILocalEvent *eventAt(int index);
  int count() const;
};

#endif // LOCAL_EVENT_LIST_MODEL_H
