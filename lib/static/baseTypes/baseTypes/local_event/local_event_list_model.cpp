#include "local_event_list_model.h"

LocalEventListModel::LocalEventListModel(QObject *parent)
  : QAbstractListModel (parent)
{
}

LocalEventListModel::~LocalEventListModel()
{

}


int LocalEventListModel::rowCount(const QModelIndex &) const
{
  return allEvents.count();
}

QVariant LocalEventListModel::data(const QModelIndex &index, int role) const
{
  int i = index.row();
  if (i < 0 || i >= allEvents.count() )
    return QVariant(QVariant::Invalid);

  return QVariant::fromValue(allEvents[i]);
}

ILocalEvent *LocalEventListModel::eventAt(int index)
{
  return allEvents[ index ];
}

int LocalEventListModel::count() const
{
  return allEvents.count();
}
