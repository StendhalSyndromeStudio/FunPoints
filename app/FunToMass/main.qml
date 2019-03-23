import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQml.Models 2.1
import QtQuick.Controls.Material 2.3

ApplicationWindow {
    id: app
    visible: true
    width: 640
    height: 480
    title: qsTr("Развлечения в массы")

    Item {
        anchors.fill: parent
        MapLeningrad{
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
                height: eventsList.height - minMaxButtons.height




//                ObjectModel {
//                        id: itemModel
//                        Rectangle {
//                            height: 30
//                            width: parent.width
//                            color: "red"
//                            Column {
//                                spacing: 3
//                                Row {
//                                    Text { text : "Картинка" }
//                                    Text { text : "Событие № " + (index + 1) }
//                                }
//                                Text { text : "Время проведения" }
//                                Text { text : "Расстояние для точки" }
//                                Text { text : "Организатор *****" }
//                            }
//                        }
//                        Rectangle {
//                            height: 30
//                            width: parent.width
//                            color: "red"
//                            Column {
//                                spacing: 3
//                                Row {
//                                    Text { text : "Картинка" }
//                                    Text { text : "Событие № " + (index + 1) }
//                                }
//                                Text { text : "Время проведения" }
//                                Text { text : "Расстояние для точки" }
//                                Text { text : "Организатор *****" }
//                            }
//                        }
//                        Rectangle {
//                            height: 30
//                            width: parent.width
//                            color: "red"
//                            Column {
//                                spacing: 3
//                                Row {
//                                    Text { text : "Картинка" }
//                                    Text { text : "Событие № " + (index + 1) }
//                                }
//                                Text { text : "Время проведения" }
//                                Text { text : "Расстояние для точки" }
//                                Text { text : "Организатор *****" }
//                            }
//                        }
//                        Rectangle {
//                            height: 30
//                            width: parent.width
//                            color: "red"
//                            Column {
//                                spacing: 3
//                                Row {
//                                    Text { text : "Картинка" }
//                                    Text { text : "Событие № " + (index + 1) }
//                                }
//                                Text { text : "Время проведения" }
//                                Text { text : "Расстояние для точки" }
//                                Text { text : "Организатор *****" }
//                            }
//                        }
//                        Rectangle {
//                            height: 30
//                            width: parent.width
//                            color: "red"
//                            Column {
//                                spacing: 3
//                                Row {
//                                    Text { text : "Картинка" }
//                                    Text { text : "Событие № " + (index + 1) }
//                                }
//                                Text { text : "Время проведения" }
//                                Text { text : "Расстояние для точки" }
//                                Text { text : "Организатор *****" }
//                            }
//                        }
//                        Rectangle {
//                            height: 30
//                            width: parent.width
//                            color: "red"
//                            Column {
//                                spacing: 3
//                                Row {
//                                    Text { text : "Картинка" }
//                                    Text { text : "Событие № " + (index + 1) }
//                                }
//                                Text { text : "Время проведения" }
//                                Text { text : "Расстояние для точки" }
//                                Text { text : "Организатор *****" }
//                            }
//                        }
//                        Rectangle {
//                            height: 30
//                            width: parent.width
//                            color: "red"
//                            Column {
//                                spacing: 3
//                                Row {
//                                    Text { text : "Картинка" }
//                                    Text { text : "Событие № " + (index + 1) }
//                                }
//                                Text { text : "Время проведения" }
//                                Text { text : "Расстояние для точки" }
//                                Text { text : "Организатор *****" }
//                            }
//                        }
//                    }

//                    ListView {
//                        anchors.fill: parent
//                        model: itemModel
//                    }

//                ListView {
//                    id: lv
//                    spacing: 10

//                    width: parent.width
//                    model: itemModel
////                    delegate: Column {
////                        spacing: 3
//////                        Rectangle{
//////                            anchors.fill: parent
//////                            radius: 5
//////                            color: "#882d2d"
//////                        }

////                        Row {
////                            Text { text : "Картинка" }
////                            Text { text : "Событие № " + (index + 1) }
////                        }
////                        Text { text : "Время проведения" }
////                        Text { text : "Расстояние для точки" }
////                        Text { text : "Организатор *****" }
////                        width: parent.width

////                    }
//                }

                ListView {
                  //anchors.fill: parent
                  model: 20
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
                                Text { text : "Событие № " + (index + 1) }
                            }
                            Text { text : "Время проведения" }
                            Text { text : "Расстояние для точки" }
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
