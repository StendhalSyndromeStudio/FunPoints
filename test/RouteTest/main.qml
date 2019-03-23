import QtQuick 2.6
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import QtPositioning 5.5
import QtLocation 5.6

//Window {
    //visible: true
    //width: 640
    //height: 480
    //title: qsTr("Hello World")

    ApplicationWindow {
        visible: true
        width: 1000
        height: 400

        PositionSource {
          id: positionSource
          active: true
        }

        Plugin {
            id: aPlugin
            name: "here"
            PluginParameter { name: "here.app_id"; value: "1zkQdmrPd2TGxOCVEZh9" }
            PluginParameter { name: "here.token"; value: "WslSrflSfYzUKhofUoA2ew" }
        }

        Map {
            id: mapview
            anchors.fill: parent
            plugin: aPlugin
            center: QtPositioning.coordinate(-27.575, 153.088)
            zoomLevel: 14

            onStateChanged: {
                console.log("state changed")
            }

            MapItemView {
                    model: routeModel
                    delegate: routeDelegate
                }

            MapItemView {
                    model: routeModel
                    delegate: mapPlaceDelegate
                }

            Component {
              id: mapPlaceDelegate
              MapQuickItem {
                coordinate: QtPositioning.coordinate(-27.575, 153.088)
                anchorPoint.x: imagePlace.width / 2
                anchorPoint.y: imagePlace.width / 2
                sourceItem: Image {
                  id: imagePlace
                  width: 35
                  height: 50
                  source: "qrc:/imgs/guitar.png"
                }
              }
            }

            Component {
                id: routeDelegate

                MapRoute {
                    route: routeData
                    line.color: "orange"
                    line.width: 5
                    smooth: true
                    opacity: 0.8
                }
            }

            MapPolyline {
              id: mapline
              line.width: 3
              line.color: 'blue'
            }

            onMapReadyChanged: {
                console.log("ready")
            }
        }

        RouteQuery {
            id: aQuery
            waypoints: [
                { latitude: -27.575, longitude: 153.088},
                { latitude: -27.465, longitude: 153.023}
            ]
            travelModes: RouteQuery.PedestrianTravel
            routeOptimizations: RouteQuery.ShortestRoute
        }

        RouteModel {
            id: routeModel
            plugin: aPlugin
            autoUpdate: true
            query: aQuery
            onStatusChanged: {
                console.log( "change status" )
            }
            onErrorChanged: {
                console.log("error")
            }
        }

        Button {
            text: "123"

            onClicked: {
                console.log("click")
                routeModel.update( )
            }
        }

        //! [Route Maneuver List3]
    }
//}
