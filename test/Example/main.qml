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
            id: lv
            function selectExample(index){
                switch((index + 1) % 3){
                case 1:
                    return FabricOfExamples.createExampleChild_1();
                case 2:
                    return FabricOfExamples.createExampleChild_2();
                default:
                    return FabricOfExamples.createExampleChild_3();
                }
            }

            function createExampleChild(index){
                var example = selectExample(index);
                console.log( "Check instanceof of item #" + (index + 1) );
                console.log( "example instanceof Example = " + (example instanceof Example) );
                console.log( "example instanceof ExampleChild_1 = " + (example instanceof ExampleChild_1) );
                console.log( "example instanceof ExampleChild_2 = " + (example instanceof ExampleChild_2) );
                example.onTestSignal.connect(function(name){
                    console.log("onTestSignal");
                });
                example.onNameChanged.connect(function(name){
                    console.log("onNameChanged");
                    console.log(name);
                });
                example.onNameDirectChanged.connect(function(name){
                    console.log("onNameDirectChanged");
                    console.log(name);
                });

                example.name = example.type + ", " + (index + 1) + " son of Example";
                example.name_direct = example.type + ", " + (index + 1) + " son of Example  (direct)";
                return example;
            }

            width: parent.width
            model: 20
            delegate: ItemDelegate {
                text: lv.createExampleChild(index).type + "___" + (index + 1)
                width: parent.width
            }
        }
    }
}
