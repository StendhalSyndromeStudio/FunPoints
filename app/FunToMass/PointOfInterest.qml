import QtQuick 2.6
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import QtPositioning 5.5
import QtLocation 5.6

Item {
    id: poi
        property string title:"123"
        property string time:"17:00 - 21:00"
        property real starScale:0.4
        property string starPath:"qrc:/imgs/star.png"

        Item {
            id: txt

            GridLayout  {
                id: layout
                visible: true
                anchors.fill: parent
                columns: 6
                rows: 2

                Image {
                    id: image
                    visible: true
                    source: "qrc:/imgs/key.png"
                    Layout.rowSpan: 2;
                    Layout.alignment: Layout.Left
                }

                Text {
                    id: idTitle
                    visible: true
                    text: title
                    font.bold: true;
                    Layout.column: 1
                    Layout.row: 0
                    Layout.columnSpan: 1;
                    Layout.alignment: Layout.Left
                }

                Text {
                    id: idTime
                    visible: true
                    text: time
                    font.bold: true;
                    Layout.column: 1
                    Layout.row: 1
                    Layout.columnSpan: 1;
                    Layout.alignment: Layout.Left
                }
                /*
                Image {
                    id: star1
                    visible: true
                    source: starPath
                    scale: starScale
                    Layout.column: 1
                    Layout.row: 1
                    Layout.alignment: Layout.Left
                }

                Image {
                    id: star2
                    visible: true
                    source: starPath
                    scale: starScale
                    Layout.column: 2
                    Layout.row: 1
                    Layout.alignment: Layout.Left
                }

                Image {
                    id: star3
                    visible: true
                    source: starPath
                    scale: starScale
                    Layout.column: 3
                    Layout.row: 1
                    Layout.alignment: Layout.Left
                }

                Image {
                    id: star4
                    visible: true
                    source: starPath
                    scale: starScale
                    Layout.column: 4
                    Layout.row: 1
                    Layout.alignment: Layout.Left
                }
                */
            }
        }
}
