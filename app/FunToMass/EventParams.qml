import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12

Rectangle {
    visible: true
    width: 640
    height: 480
    id:eventParamsId
    //title: qsTr("Hello World")

    function updateData( type, time, title ) {
        createNewPoi( type, time, title )
    }

    signal createNewPoi( string type, int hour, string title )

    ColumnLayout {
        id: columnLayout
        spacing: 1
        anchors.fill: parent

        Text {
            text: "Менеджер концертов"
            font.bold: true
            font.pointSize: 24
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Text {
            id: element
            text: qsTr("Тип мероприятия")
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignHCenter
            rightPadding: 10
            leftPadding: 10
            font.family: "Tahoma"
            font.pixelSize: 20
        }

        Rectangle {
            id: rectType
            width: 200
            height: 200
            color: "#ffffff"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

            GridLayout {
                id: gridLayout
                height: 100
                anchors.rightMargin: 20
                anchors.leftMargin: 20
                anchors.right: parent.right
                anchors.left: parent.left
                anchors.top: parent.top

                ComboBox {
                    id: comboBox1
                    Layout.minimumHeight: 0
                    Layout.fillWidth: true
                    model: [ "Квартирник", "Уличный концерт", "Рэп-баттл" ]
                }
            }
        }

        Text {
            id: timeCaption
            text: qsTr("14:00")
            Layout.fillWidth: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 16
        }

        Rectangle {
            id: rectTime
            width: 200
            height: 200
            color: "#fdfdfd"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.fillWidth: true
            GridLayout {
                id: gridLayout1
                height: 100
                anchors.rightMargin: 20
                anchors.top: parent.top
                anchors.right: parent.right
                anchors.left: parent.left
                Text {
                    id: element1
                    text: qsTr("Время")
                    rightPadding: 10
                    leftPadding: 10
                    font.pixelSize: 20
                }

                Slider {
                    id: element6
                    Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                    Layout.maximumWidth: 500
                    tickmarksEnabled: true
                    stepSize: 1
                    maximumValue: 23
                    Layout.fillWidth: true
                    value: 14

                    onValueChanged: {
                        timeCaption.text = "Начало в " + element6.value + ":00";
                    }
                }

            }

            Layout.fillHeight: true
        }

        Text {
            id: timeCaption1
            text: qsTr("Название")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 16
            Layout.fillWidth: true
        }

        Rectangle {
            id: rectDistance
            width: 200
            height: 200
            color: "#ffffff"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.fillWidth: true
            Layout.fillHeight: true

            RowLayout {
                id: rowLayout
                anchors.fill: parent

                TextField {
                    id: textField
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    placeholderText: qsTr("Text Field")
                }
            }
        }

        Button {
            id: button
            height: 60
            text: qsTr("Применить")
            Layout.fillHeight: true
            Layout.minimumHeight: 70
            Layout.minimumWidth: 50
            Layout.fillWidth: true

            onClicked: {
                updateData( comboBox1.currentText, element6.value, textField.text )
                eventParamsId.visible = false
            }
        }

    }
}




/*##^## Designer {
    D{i:5;anchors_height:100;anchors_width:100}D{i:9;anchors_height:100;anchors_width:100}
D{i:14;anchors_height:100;anchors_width:100;anchors_x:0;anchors_y:0}D{i:13;invisible:true}
D{i:1;anchors_height:100;anchors_width:100}
}
 ##^##*/
