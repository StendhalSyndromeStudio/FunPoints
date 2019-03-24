import QtQuick 2.9
import QtQuick.Window 2.2
import QtMultimedia 5.4
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0

Rectangle {
    visible: true

    id : cameraUI
    anchors.fill: parent

    color: "#000000"

    signal exit( )

    Camera {
        id: camera
        captureMode: Camera.CaptureStillImage
/*
        imageCapture {
            onImageCaptured: {
                photoPreview.source = preview
                stillControls.previewAvailable = true
                cameraUI.state = "PhotoPreview"
            }
        }
*/
        videoRecorder {
             resolution: "640x480"
             frameRate: 30
        }
    }
//    ColumnLayout {
        //anchors.fill: parent
/*
        PhotoPreview {
            id : photoPreview
            anchors.fill : parent
            onClosed: cameraUI.state = "PhotoCapture"
            visible: cameraUI.state == "PhotoPreview"
            focus: visible
        }
*/
        VideoOutput {
            id: viewfinder
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            visible: true
/*
            x: 0
            y: 0
            width: cameraUI.width
            height: cameraUI.height
*/
            source: camera
            autoOrientation: true
        }

        RowLayout {
            height: 48
            scale: 1
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.top: parent.top

            Button {
                height: 84
                text:"ОПЛАТИТЬ"
                scale: 1
                leftPadding: 8
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                Layout.fillWidth: false

                onClicked: {
                    if ( money.text == 'ПОТРАЧЕНО!' ) {
                        money.text = '500 рублей'
                    }
                    else
                        money.text = 'ПОТРАЧЕНО!'
                }
            }

            Text {
                id:money
                color: "#ffffff"
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                text: "500 рублей"
                topPadding: 13
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 20
                font.weight: Font.ExtraLight
                font.capitalization: Font.AllLowercase
                fontSizeMode: Text.VerticalFit
                horizontalAlignment: Text.AlignHCenter
                Layout.fillWidth: false
                style: Text.Raised
                font.family: "Courier"
                font.bold: true
            }

            Button {
                height: 84
                text:"Закрыть"
                scale: 1
                leftPadding: 8
                Layout.alignment: Qt.AlignRight | Qt.AlignTop
                Layout.fillWidth: false

                onClicked: {
                    cameraUI.visible = false
                    exit( )
                }
            }
    }
}






