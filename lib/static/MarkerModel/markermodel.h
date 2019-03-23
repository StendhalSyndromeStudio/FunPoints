#ifndef MARKERMODEL_H
#define MARKERMODEL_H

#include <QAbstractListModel>
#include <QGeoCoordinate>
#include <QDateTime>
#include <QMap>

class MarkerModel : public QAbstractListModel {
    Q_OBJECT
public:
    using QAbstractListModel::QAbstractListModel;
    enum MarkerRoles{ positionRole = Qt::UserRole + 1 };

    Q_INVOKABLE void addMarker( const QGeoCoordinate &coordinate, const QString &title = "Концерт №", QDateTime start = QDateTime::currentDateTime( ), QDateTime end = QDateTime::currentDateTime( ) ) {
        beginInsertRows( QModelIndex( ), rowCount( ), rowCount( ) );
        m_Titles[ coordinate.toString( ) ] = title;
        //_title = title;
        _startEvent = start;
        _endEvent = end;
        m_coordinates.append( coordinate );
        endInsertRows( );
    }

    int rowCount( const QModelIndex &parent = QModelIndex( ) ) const override {
        Q_UNUSED( parent )
        return m_coordinates.count( );
    }

    QVariant data( const QModelIndex &index, int role = Qt::DisplayRole ) const override {
        if ( index.row( ) < 0 || index.row( ) >= m_coordinates.count( ) )
            return QVariant( );
        if ( role== MarkerModel::positionRole )
            return QVariant::fromValue( m_coordinates[ index.row( ) ] );
        return QVariant( );
    }

    QHash<int, QByteArray> roleNames( ) const override {
        QHash<int, QByteArray> roles;
        roles[ positionRole ] = "position";
        return roles;
    }
signals:
    void changeData( QGeoCoordinate geoData );
public slots:
    QGeoCoordinate nextPoint( );
    void selectPoint( QGeoCoordinate geoData );
    QString title( const QGeoCoordinate &coordinate ) const;
    void title( QString v );
    QString time( ) const;
private:
    QList<QGeoCoordinate> m_coordinates;
    QMap<QString, QString> m_Titles;
    int _currentPoint{ 0 };
    QString _title;
    QDateTime _startEvent;
    QDateTime _endEvent;
};

#endif // MARKERMODEL_H
