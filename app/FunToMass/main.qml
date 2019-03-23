import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    id: app
    visible: true
    width: 640
    height: 480
    title: qsTr("Развлечения в массы")

    Item {
        anchors.fill: parent
        MapDummy{
            id: map
        }

        ControlButtons {
            width: 70
            height: 300//contentItem.height
            anchors.right: map.right
            anchors.bottom: map.bottom
            anchors.bottomMargin: 20
            anchors.rightMargin: 20
        }
        Item {
            id: eventsList
            //anchors.fill: parent
            width: parent.width
            height: 300
            //color: "#2d2d2d"
            anchors.bottom: map.bottom
            MinMaxButtons {
                id: minMaxButtons
                width: 50
                height: 110
                anchors.bottom: eventsContainer.top
            }

//            Rectangle {
//                id: eventsListMax
//                anchors.top: parent.top
//                width: parent.width
//                height: 30
//                radius: 10
//                color: "#2d2d2d"
//                MouseArea {
//                        id: mouseAreaMax
//                        anchors.fill: parent
//                        onClicked: eventsList.state = 'maximized';
//                    }
//            }
//            Rectangle {
//                id: eventsListMin
//                anchors.top: eventsListMax.bottom
//                width: parent.width
//                height: 30
//                radius: 10
//                color: "#2d2d2d"
//                MouseArea {
//                        id: mouseAreaMin
//                        anchors.fill: parent
//                        onClicked: eventsList.state = 'minimized';
//                    }
//            }
            ScrollView {
                id: eventsContainer
                anchors.left: parent.left
                anchors.right: parent.right
                //anchors.bottom: map.bottom
                //height: map.height / 2
                ListView {
                    id: lv


                    width: parent.width
                    model: 20
                    delegate: ItemDelegate {
                        text: "Событие № " + (index + 1)
                        width: parent.width
                    }
                }
            }
            states: [
                State {
                    name: "minimized"
                    PropertyChanges { target: eventsList; height: 100 }
                },
                State {
                    name: "maximized"
                    PropertyChanges { target: eventsList; height: eventsList.parent.height }
                },
                State {
                    name: "normal"
                    PropertyChanges { target: eventsList; height: eventsList.parent.height / 2 }
                }
            ]
        }
    }
}
