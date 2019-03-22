import QtQuick 2.9
import QtQuick.Controls 2.2
import com.fun.fabric 1.0
import com.fun.example 1.0
import com.fun.example_child_1 1.0
import com.fun.example_child_2 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")

    ScrollView {
        anchors.fill: parent

        ListView {
            width: parent.width
            model: 20
            delegate: ItemDelegate {
                text: ( (index + 1) % 2 === 0 ? FabricOfExamples.createExampleChild_1().type : FabricOfExamples.createExampleChild_2().type ) + "___" + index + 1
                width: parent.width
            }
        }
    }
}
