import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.3

Item {
    id: main
    //property alias maximize: maximize
    //property alias minimize: minimize
    signal maximizeClicked()
    signal minimizeClicked()
    Item{
        anchors.fill: parent
        ColumnLayout {
            spacing: 0
            anchors.fill: parent
            ControlButton {
                id: maximize
                //text: "^"
//                signal click();
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: parent.width
                Layout.topMargin: 0
                Layout.bottomMargin: 0
                onClicked: main.maximizeClicked()
                Image {
                    anchors.fill: parent
                    source: "imgs/arrow_up.png"
                }
            }
            ControlButton{
                id: minimize
                //text: "v"
//                signal click();
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: parent.width
                Layout.topMargin: 0
                Layout.bottomMargin: 0
                onClicked: main.minimizeClicked()
                Image {
                    anchors.fill: parent
                    source: "imgs/arrow_down.png"
                }
            }
        }
    }

}
