import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQml 2.12

Window {
    minimumWidth: 480
    minimumHeight: 640
    visible: true
    title: qsTr("AudioPlayer")
    color: "steelblue"

    property bool isPlaying: false
    property int currentTime: 0
    property int totalTime: 100

    Column {
        anchors.fill: parent
        spacing: 10
        padding: 10

        Rectangle {
            id: audioScreen
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
            width: parent.width * 0.8
            height: parent.height * 0.6
            color: "gray"
            radius: 10
            property string currentAction: "Waiting..."

            Text {
                anchors.centerIn: parent
                text: audioScreen.currentAction
                font.pixelSize: 20
            }
        }

        ProgressBar {
            id: progressBar
            from: 0
            to: totalTime
            value: currentTime
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: audioScreen.bottom
            anchors.topMargin: 40
            onValueChanged: {
                currentTime = progressBar.value;
            }
            width: parent.width * 0.8

            Timer {
                interval: 1000
                running: true
                repeat: true
                onTriggered: {
                    if (isPlaying && currentTime < totalTime) {
                        currentTime += 1;
                    }
                    if (currentTime >= totalTime) {
                        isPlaying = false;
                        currentTime = totalTime;
                        audioScreen.currentAction = "Stop"
                    }
                }
            }
        }

        Row {
            id: controlButtons
            spacing: 45
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: progressBar.bottom
            anchors.topMargin: 20
            width: parent.width * 0.8

            Button {
                id: rewindButton
                text: "⏪"
                height: 40
                width: 40
                padding: 0
                font.pixelSize: 46
                background: Rectangle {
                        color: "transparent"
                        border.color: "transparent"
                        border.width: 1
                        radius: 10
                    }
                onClicked: {
                    if (currentTime > 0) {
                        currentTime -= 5;
                        audioScreen.currentAction = "Rewind";
                        var resetTimer = Qt.createQmlObject('import QtQuick 2.12; Timer { interval: 1000; onTriggered: { audioScreen.currentAction = isPlaying ? "Play" : "Pause" } }', audioScreen);
                        resetTimer.start();
                    }
                }
                ToolTip {
                    text: "Rewind"
                }
            }

            Button {
                id: playButton
                text: "▶"
                height: 40
                width: 40
                padding: 0
                font.pixelSize: 46
                background: Rectangle {
                        color: "transparent"
                        border.color: "transparent"
                        border.width: 1
                        radius: 10
                    }
                onClicked: {
                    if (!isPlaying) {
                        isPlaying = true;
                        audioScreen.currentAction = "Play"
                    } else {
                        isPlaying = false;
                        audioScreen.currentAction = "Pause"
                    }
                }
                ToolTip {
                    text: "Play/Pause"
                }
            }

            Button {
                id: pauseButton
                text: "⏸"
                height: 40
                width: 40
                padding: 0
                font.pixelSize: 46
                background: Rectangle {
                        color: "transparent"
                        border.color: "transparent"
                        border.width: 1
                        radius: 10
                    }
                onClicked: {
                    isPlaying = false;
                    audioScreen.currentAction = "Pause"
                }
                ToolTip {
                    text: "Pause"
                }
            }

            Button {
                id: stopButton
                text: "⏹"
                height: 40
                width: 40
                padding: 0
                font.pixelSize: 46
                background: Rectangle {
                        color: "transparent"
                        border.color: "transparent"
                        border.width: 1
                        radius: 10
                    }
                onClicked: {
                    isPlaying = false;
                    currentTime = 0;
                    audioScreen.currentAction = "Stop"
                }
                ToolTip {
                    text: "Stop"
                }
            }

            Button {
                id: forwardButton
                text: "⏩"
                height: 40
                width: 40
                padding: 0
                font.pixelSize: 46
                background: Rectangle {
                        color: "transparent"
                        border.color: "transparent"
                        border.width: 1
                        radius: 10
                    }
                onClicked: {
                    if (currentTime < totalTime) {
                        currentTime += 5;
                        audioScreen.currentAction = "Forward"
                        var resetTimer = Qt.createQmlObject('import QtQuick 2.12; Timer { interval: 1000; onTriggered: { audioScreen.currentAction = isPlaying ? "Play" : "Pause" } }', audioScreen);
                        resetTimer.start();
                    }
                }
                ToolTip {
                    text: "Forward"
                }
            }
        }
    }
}
