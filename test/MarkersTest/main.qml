import QtQuick 2.6
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import QtPositioning 5.5
import QtLocation 5.6
import org.simplemarkermodel.markermodel 1.0

/*
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
}
*/

ApplicationWindow {
    id: app
    visible: true
    width: 640
    height: 480
    title: qsTr("test")

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
        center: QtPositioning.coordinate(59.91, 10.75)
        zoomLevel: 14

        MapItemView{
            model: markerModel
            delegate: mapcomponent
        }

        MapItemView{
            model: markerModel
            delegate: mapcomponentTxt
        }
    }

    Component {
        id: mapcomponent

        MapQuickItem {
            id: marker
            anchorPoint.x: image.width/4
            anchorPoint.y: image.height
            coordinate: position

            sourceItem: Image {
                id: image
                //source: "http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_red.png"
                source: "qrc:/imgs/guitar.png"

            }
        }
    }

    Component {
        id: mapcomponentTxt

        MapQuickItem {
            id: markerTxt
            anchorPoint.x: -20
            anchorPoint.y: 10
            coordinate: position

            sourceItem: Text {
                id: txt
                //source: "http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_red.png"
                text: "Концерт"
            }
        }
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            var coordinate = mapview.toCoordinate(Qt.point(mouse.x,mouse.y))
            console.log( "click:", coordinate );
        }

        onPressAndHold:  {
            var coordinate = mapview.toCoordinate( Qt.point(mouse.x,mouse.y ) )
            console.log( "setMarker:", coordinate );
            markerModel.addMarker( coordinate )
        }
    }

    MarkerModel {
        id:markerModel
    }
}
