#include "markermodel.h"
#include <QtDebug>
#include <QTime>

QGeoCoordinate MarkerModel::nextPoint( )  {
    if ( m_coordinates.isEmpty( ) )
        return QGeoCoordinate( );
    qDebug( ) << "currentPoint:" << _currentPoint << "<" << m_coordinates.count( );
    if ( _currentPoint < m_coordinates.count( ) - 1 ) {
        _currentPoint++;
    }
    else {
        _currentPoint = 0;
    }
    emit changeData( m_coordinates.at( _currentPoint ) );
    return  m_coordinates.at( _currentPoint );
}

QString MarkerModel::title( ) const {
    return _title + QString::number( m_coordinates.count( ) );
}

QString MarkerModel::time( ) const {
    auto current = _startEvent;
    current = current.addSecs( 60 * m_coordinates.count( ) );
    auto last = _endEvent;
    last = last.addSecs( 3600 * m_coordinates.count( ) );
    return ( current.toString( "hh:mm" ) + "-" + last.toString( "hh:mm" ) );
}
