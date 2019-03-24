import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.3

Item {
    id: main
    signal listEventsClicked()
    signal filterClicked()
    signal payClick
    Item{
        anchors.fill: parent
        ColumnLayout {
            anchors.fill: parent
            ControlButton {
                id: addEvent
                text: "+"
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: parent.width
                onClicked: main.payClick();
            }
            ControlButton{
                id: filterEvents
                text: "Y"
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: parent.width
                onClicked: main.filterClicked();
            }
            ControlButton{
                id: myLocation
                text: "^"
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: parent.width
            }
            ControlButton{
                id: listEvents
                text: "M"
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: parent.width
                onClicked: main.listEventsClicked();
            }
        }
    }

}
