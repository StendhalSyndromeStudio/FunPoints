import QtQuick 2.6
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import QtPositioning 5.5
import QtLocation 5.6
import org.simplemarkermodel.markermodel 1.0

ApplicationWindow {
    property real myX: 59.995881
    property real myY: 30.291263

    property variant locationLeningrad: QtPositioning.coordinate( myX, myY )

    id: app
    visible: true
    width: 720
    height: 1280
    title: qsTr("Map")

    Connections {
        target: markerModel
        onChangeData: {
            var coordinate =  geoData;
            aQuery.clearWaypoints( );
            aQuery.addWaypoint( locationLeningrad )
            aQuery.addWaypoint( coordinate )
            routeModel.update( )
        }
    }
    // слот для остлеживания изменения дистанции до выбранной точки
    Connections {
        target: routeModel
        onUpdateDistance: {
            console.log( "update distance", distance )
            app.title = distance
        }
    }

    Plugin {
        id: mapPlugin
        name: "here"
        PluginParameter { name: "here.app_id"; value: "1zkQdmrPd2TGxOCVEZh9" }
        PluginParameter { name: "here.token"; value: "WslSrflSfYzUKhofUoA2ew" }
    }

    Map {
        id: mapview
        anchors.fill: parent
        plugin: mapPlugin
        center: locationLeningrad
        zoomLevel: 16
        // Значок события
        // Наша позиция на карте
        MapItemView {
            model: myPosModel
            delegate: myPosition
        }
        MapItemView {
            model: markerModel
            delegate: poiComp
        }

        MapItemView {
                model: routeModel
                delegate: routeDelegate
        }

        MapItemView {
            model: routeModel
            delegate: poiComp
        }

        onMapReadyChanged: {
            console.log( "changeReady" )
            myPosModel.addMarker( locationLeningrad )
            routeModel.update( )
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                //var coordinate = mapview.toCoordinate(Qt.point(mouse.x,mouse.y))
                //console.log( "click:", coordinate );
            }

            onPressAndHold:  {
                var coordinate = mapview.toCoordinate( Qt.point( mouse.x,mouse.y ) )
                console.log( "setMarker:", coordinate );
                markerModel.addMarker( coordinate )

                markerModel.selectPoint( coordinate )

                mapview.update( )
            }
        }
        // моя позиция
        Component {
            id: myPosition

            MapQuickItem {
                id: markerMy
                anchorPoint.x: img.width * 0.5
                anchorPoint.y: img.height
                coordinate: position

                sourceItem: Image {
                    id: img
                    source: "qrc:/imgs/circle.png"
                }
            }
        }
        // точка интереса
        Component {
            id:poiComp

            MapQuickItem {
                id: marker
                coordinate: position
                anchorPoint.x: 25
                anchorPoint.y: 53
                sourceItem: PointOfInterest {
                    id:concretePoi
                    title: markerModel.title( );
                    time: markerModel.time( );
                }
            }
        }
        // маршрут
        Component {
            id: routeDelegate

            MapRoute {
                route: routeData
                line.color: "blue"
                line.width: 5
                smooth: true
            }
        }
    }
    // фабрика точек интересов
    MarkerModel {
        id:markerModel
    }
    // текущая позиция
    MarkerModel {
        id:myPosModel
    }
    // построение маршрутов
    RouteQuery {
        id: aQuery
        travelModes: RouteQuery.PedestrianTravel
        routeOptimizations: RouteQuery.ShortestRoute
    }

    RouteModel {
        id: routeModel
        plugin: mapPlugin
        autoUpdate: true
        query: aQuery
        // сигнал с дистанцией до точки интереса
        signal updateDistance( real distance )

        onStatusChanged: {

            switch ( routeModel.status ){
            case RouteModel.Null :
                console.log( "RouteModel change status null", routeModel.status )
                break;
            case RouteModel.Loading:
                console.log( "RouteModel change status Loading", routeModel.status )
                break;
            case RouteModel.Ready :
                console.log( "RouteModel change status Ready", routeModel.status )
                var route = routeModel.get(0)
                console.log( "distance", route.distance )
                updateDistance( route.distance )
                mapview.update( )
                break;
            case RouteModel.Error:
                console.log( "RouteModel change status error", routeModel.errorString )
                break;
            }
        }
        onErrorChanged: {
            console.log("RouteModel error")
        }
    }

    // UI
    Button {
        id:nextBtn
        text: 'Построить маршрут'
        onClicked: {
            markerModel.nextPoint( );
            routeModel.update( )
            /*
            var coordinate=  markerModel.nextPoint( );
            aQuery.clearWaypoints( );
            aQuery.addWaypoint( locationLeningrad )
            aQuery.addWaypoint( coordinate )
            routeModel.update( )
            */
        }
    }
}
