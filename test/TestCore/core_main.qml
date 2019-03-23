import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12
import QtPositioning 5.5
import QtLocation 5.6
import com.fun.fpcore 1.0

ApplicationWindow {
    //anchors.fill: parent

    //! [Initialize Plugin]
    Plugin {
        id: myPlugin
        name: "here"
        PluginParameter { name: "here.app_id"; value: "1zkQdmrPd2TGxOCVEZh9" }
        PluginParameter { name: "here.token"; value: "WslSrflSfYzUKhofUoA2ew" }
    }
    //! [Initialize Plugin]

    //! [Current Location]
    PositionSource {
        id: positionSource
        property variant lastSearchPosition: FpCore.location()
        active: true
        updateInterval: 2000
        onPositionChanged:  {
            updateLocation();

            var currentPosition = FpCore.location();
            map.center = currentPosition
            var distance = currentPosition.distanceTo(lastSearchPosition)
            if (distance > 200 ) {
                lastSearchPosition = currentPosition
                searchModel.searchArea = QtPositioning.circle(currentPosition)
                searchModel.update()
            }
        }
    }
    //! [Current Location]

    //! [PlaceSearchModel]

    PlaceSearchModel {
        id: searchModel

        plugin: myPlugin

        searchTerm: "Вареники"
        searchArea: QtPositioning.circle(FpCore.location())

        Component.onCompleted: update()
    }
    //! [PlaceSearchModel]

    //! [Places MapItemView]
    ColumnLayout {
        id: layout
        anchors.fill: parent
        spacing: 1

        Map {
            id: map
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumWidth: 400;
            Layout.minimumHeight: 400;

            plugin: myPlugin;
            center: locationOslo
            zoomLevel: 13

            MapItemView {
                model: searchModel
                delegate: MapQuickItem {
                    coordinate: place.location.coordinate

                    anchorPoint.x: image.width * 0.5
                    anchorPoint.y: image.height

                    sourceItem: Column {
                        Image { id: image; source: "marker.png" }
                        Text { text: title; font.bold: true }
                    }
                }
            }
        }

        TextArea {
            id: logArea
            Layout.fillWidth: true

            text: ""
            font.pointSize: 12

            function add(message) {
                append( "[" + new Date().toLocaleTimeString() + "] " + message + "\n" );
            }
        }
    }

    //! [Places MapItemView]

    Connections {
        target: searchModel
        onStatusChanged: {
            if (searchModel.status == PlaceSearchModel.Error)
                console.log(searchModel.errorString());
        }
    }

    Component.onCompleted: {
        console.log( "on completed" );
        FpCore.onUpdateLocation.connect( updateLocation );
        FpCore.onConnected.connect( connectedToServer );
        FpCore.onDisconnected.connect( connectedToServer );
        FpCore.onError.connect( coreError );
        FpCore.onMessage.connect( coreMessage );
        updateLocation();
        logArea.add( qsTr( "Приложение инициализировано" ) );

        console.log( FpCore.eventCount() );
        for(var i = 0; i < FpCore.eventCount(); ++i) {
            logArea.add ( FpCore.eventAt( i ).name() );
        }
    }

    function updateLocation() {
//        logArea.add( qsTr( "Геолокация обновлена" ) );
    }

    function connectedToServer() {
        logArea.add( qsTr( "Подключен к серверу" ) );
    }

    function disconnectedFromServer() {
        logArea.add( qsTr( "Отключен от сервера" ) );
    }

    function coreError(code, message) {
        logArea.add( qsTr( "Ошибка: %1: %2" ).arg( code ).arg( message ) );
    }

    function coreMessage(message) {
        logArea.add( qsTr( "Сообщение: %1" ).arg( message ) );
    }
}
