import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 71
    visible: true
    title: qsTr("Some player")
    minimumHeight: 43 + 28
    minimumWidth: 180
    maximumHeight: 71

    Rectangle {
        id: screen
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 3
        height: 40
        border.color: "green"
        color: "lightgrey"

        Text {
            id: screenText
            text: qsTr("Some composition")
            anchors.verticalCenter: parent.verticalCenter
            x: 3
        }
    }

    component ContolButton: Button {
        text: qsTr("▶️")
        font.pixelSize: 15
        height: 25
        width: height
        anchors.top: screen.bottom
        anchors.topMargin: 3

        background: Rectangle {
               color: parent.down ? "balck" : "#0079d8"
        }

        contentItem: Label {
            text: parent.text
            font: parent.font
            color: "white"
            horizontalAlignment: "AlignHCenter"
            verticalAlignment: "AlignVCenter"
        }
    }

    ContolButton {
        id: playButton
        text: "\u23F5"
        anchors.left: screen.left
    }

    ContolButton {
        id: pauseButton
        text: "\u23F8"
        anchors.left: playButton.right
        anchors.leftMargin: 3
    }

    ContolButton {
        id: stopButton
        text: "\u23F9"
        anchors.left: pauseButton.right
        anchors.leftMargin: 3
    }

    ContolButton {
        id: rewindButton
        text: "\u23EA"
        anchors.left: stopButton.right
        anchors.leftMargin: 3
    }

    ContolButton {
        id: forwardButton
        text: "\u23E9"
        anchors.left: rewindButton.right
        anchors.leftMargin: 3
    }

    ProgressBar {
        id: progressBarMelody
        height: 25
        anchors.top: screen.bottom
        anchors.left: forwardButton.right
        anchors.right: screen.right
        anchors.margins: 3

    }
}
