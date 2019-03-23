import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.3

Item {
    id: main
    Item{
        anchors.fill: parent
        ColumnLayout {
            spacing: 0
            anchors.fill: parent
            ControlButton {
                id: maximize
                text: "^"
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: parent.width
                Layout.topMargin: 0
                Layout.bottomMargin: 0
            }
            ControlButton{
                id: minimize
                text: "v"
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: parent.width

            }
        }
    }

}
