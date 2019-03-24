import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12

Rectangle {
    visible: true
    anchors.fill: parent
    id:filterringPage

    signal accept( )

    ColumnLayout {
        id: columnLayout
        spacing: 1
        anchors.fill: parent

        Text {
            text: "Выбор фильтров"
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
                    model: [ "Квартирник", "Выставка", "Квест" ]
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
            text: qsTr("5 балов")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 16
            Layout.fillWidth: true
        }

        Rectangle {
            id: rectRating
            width: 200
            height: 200
            color: "#ffffff"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.fillWidth: true
            GridLayout {
                id: gridLayout2
                height: 100
                anchors.rightMargin: 20
                anchors.top: parent.top
                anchors.right: parent.right
                anchors.left: parent.left
                Text {
                    id: element2
                    text: qsTr("Рейтинг")
                    rightPadding: 10
                    leftPadding: 10
                    font.pixelSize: 20
                }

                Slider {
                    id: element4
                    Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                    Layout.maximumWidth: 500
                    tickmarksEnabled: true
                    stepSize: 1
                    maximumValue: 5
                    Layout.fillWidth: true
                    value: 5

                    onValueChanged: {
                        timeCaption1.text = "Рейтинг организатора " + element4.value + " балла";
                    }
                }

            }
            Layout.fillHeight: true
        }

        Text {
            id: timeCaption2
            text: qsTr("100 метров")
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
            GridLayout {
                id: gridLayout3
                height: 100
                anchors.rightMargin: 20
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.left: parent.left
                Text {
                    id: element3
                    text: qsTr("Растояние")
                    rightPadding: 10
                    leftPadding: 10
                    font.pixelSize: 20
                }

                Slider {
                    id: element5
                    Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                    Layout.maximumWidth: 500
                    tickmarksEnabled: true
                    stepSize: 1
                    maximumValue: 1000
                    Layout.fillWidth: true
                    value: 100;

                    onValueChanged: {
                        timeCaption2.text = "Расстояние " + element5.value + " метров";
                    }
                }

            }
            Layout.fillHeight: true
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
                filterringPage.visible = false
                accept( )
            }
        }

    }
}


/*##^## Designer {
    D{i:5;anchors_height:100;anchors_width:100}D{i:9;anchors_height:100;anchors_width:100}
D{i:14;anchors_height:100;anchors_width:100}D{i:19;anchors_height:100;anchors_width:100}
D{i:1;anchors_height:100;anchors_width:100}
}
 ##^##*/
