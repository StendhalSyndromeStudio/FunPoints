import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.3

Item {
    id: main
    signal listEventsClicked()
    signal filterClicked()
    signal payClick()
    signal locationClicked()
    Item{
        anchors.fill: parent
        ColumnLayout {
            anchors.fill: parent
            ControlButton {
                id: addEvent
                text: ""//"+"
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: parent.width
                onClicked: main.payClick();
                Image {
                    anchors.fill: parent
                    source: "imgs/donate.png"
                }
                //icon.source: "imgs/donate.png"
            }
            ControlButton{
                id: filterEvents
                text: ""//"Y"
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: parent.width
                onClicked: main.filterClicked();
                Image {
                    anchors.fill: parent
                    source: "imgs/filter.png"
                }
                //icon.source: "imgs/filter.png"
            }
            ControlButton{
                id: myLocation
                text: ""//"^"
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: parent.width
                onClicked: main.locationClicked();
                Image {
                    anchors.fill: parent
                    source: "imgs/location.png"
                }

            }
            ControlButton{
                id: listEvents
                text: ""//"M"
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: parent.width
                onClicked: main.listEventsClicked();
                Image {
                    anchors.fill: parent
                    source: "imgs/events.png"
                }
//                icon.source: "imgs/events.png"
//                icon.name: "control-events"
            }
        }
    }

}
