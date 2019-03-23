import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.3

Item {
    id: main
    Item{
        anchors.fill: parent
        ColumnLayout {
            anchors.fill: parent
            ControlButton {
                id: addEvent
                text: "+"
            }
            ControlButton{
                id: filterEvents
                text: "Y"
            }
            ControlButton{
                id: myLocation
                text: "^"
            }
            ControlButton{
                id: listEvents
                text: "M"
            }
        }
    }

}
