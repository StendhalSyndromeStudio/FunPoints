import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQml.Models 2.1
import QtQuick.Controls.Material 2.3
import com.fun.fpcore 1.0
import "ComponentFactory.js" as Factory

ApplicationWindow {
    id: app
    visible: true
    width: 640
    height: 480
    title: qsTr("Развлечения в массы")

    Item {
        anchors.fill: parent
        MapLeningrad {
        //MapDummy {
            id: map
        }

        ControlButtons {
            width: 70
            height: 300//contentItem.height
            anchors.right: map.right
            anchors.bottom: map.bottom
            anchors.bottomMargin: 20
            anchors.rightMargin: 20
            onListEventsClicked : {
                eventsList.state = "half";
            }
        }
        Item {
            id: eventsList
            //anchors.fill: parent
            width: parent.width
            height: 300
            //color: "#2d2d2d"
            anchors.bottom: map.bottom
            //color: "#2d2d2d"


            /*
        for(var i = 0; i < FpCore.eventCount(); ++i) {
            var event = FpCore.eventAt( i );
            var coordinate = event.location( );
            //var timeSpan = event.timeSpending( ).span;
            var title = event.name( );
            console.log( "add point", title );
            markerModel.addMarker( coordinate, title  )
            //markerModel.title( title );
            //markerModel.selectPoint( coordinate )

            mapview.update( )
        }

*/


            ListModel {
                id: eventsModel
                Component.onCompleted: {


                    for(var idx = 0; idx < FpCore.eventCount(); ++idx){
                        var event = FpCore.eventAt( idx );
                        var listElem = {};
                        listElem.name = event.name( );
                        listElem.coordinate = event.location( );
                        eventsModel.insert(idx,listElem);

                    }
                }
            }

            ScrollView {
                id: eventsContainer
                anchors.left: parent.left
                anchors.right: parent.right
                //anchors.bottom: map.bottom
                height: eventsList.height - minMaxButtons.height


                ListView {
                  //anchors.fill: parent
                  model: eventsModel
                  id: lv
                  spacing: 10
                  width: parent.width

                  delegate:
                    Rectangle {
                        width: parent.width
                        height: 70
                        color: index % 2 == 0 ? "#993030" : "#883040"
                        radius: 10
                        Column {
                            spacing: 3
                            Row {
                                Text { text : "Картинка" }
                                Text { text : name }
                            }
                            Text { text : "Время проведения" }
                            Text { text : coordinate }
                            Text { text : "Организатор *****" }
                        }
                    }
                }


            }
            MinMaxButtons {
                id: minMaxButtons
                width: 40
                height: 50
                anchors.bottom: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
//                maximizeClick: console.log("111111111111");
//                minimizeClick: console.log("111111111111");
                onMaximizeClicked: {
                    if(eventsList.state === "half"){
                        eventsList.state = "maximized";
                    } else if(eventsList.state === "minimized") {
                        eventsList.state = "half";
                    }
                }
                onMinimizeClicked: {
                    if(eventsList.state === "half"){
                        eventsList.state = "minimized";
                    } else if(eventsList.state === "maximized") {
                        eventsList.state = "half";
                    }
                }

            }

            states: [
                State {
                    name: "minimized"
                    PropertyChanges { target: eventsList; height: 100; visible: false }
                },
                State {
                    name: "maximized"
                    PropertyChanges { target: eventsList; height: eventsList.parent.height }
                },
                State {
                    name: "half"
                    PropertyChanges { target: eventsList; height: eventsList.parent.height / 2 }
                }
            ]
            state: "half"
        }
    }
}
