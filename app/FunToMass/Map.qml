import QtQuick 2.0

import QtPositioning 5.5
import QtLocation 5.6

Rectangle {
    anchors.fill: parent

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
        property variant lastSearchPosition: locationOslo
        active: true
        updateInterval: 2000 // 2 mins
        onPositionChanged:  {
            var currentPosition = positionSource.position.coordinate
            map.center = currentPosition
            var distance = currentPosition.distanceTo(lastSearchPosition)
            if (distance > 500) {
                // 500m from last performed pizza search
                lastSearchPosition = currentPosition
                searchModel.searchArea = QtPositioning.circle(currentPosition)
                searchModel.update()
            }
        }
    }
    //! [Current Location]

    //! [PlaceSearchModel]
    property variant locationOslo: QtPositioning.coordinate( 59.93, 10.76)

    PlaceSearchModel {
        id: searchModel

        plugin: myPlugin

        searchTerm: "Pizza"
        searchArea: QtPositioning.circle(locationOslo)

        Component.onCompleted: update()
    }
    //! [PlaceSearchModel]

    //! [Places MapItemView]
    Map {
        id: map
        anchors.fill: parent
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
    //! [Places MapItemView]

    Connections {
        target: searchModel
        onStatusChanged: {
            if (searchModel.status == PlaceSearchModel.Error)
                console.log(searchModel.errorString());
        }
    }
}

