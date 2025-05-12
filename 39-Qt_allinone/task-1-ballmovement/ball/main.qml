/*Приложение отображает одно окно, в котором есть два квадрата и круг.
При нажатии на левый квадрат круг перемещается в сторону правого квадрата на произвольное количество пикселей.
При нажатии на правый квадрат круг возвращается в исходное положение.
При достижении кругом любой стороны правого квадрата или его центра круг возвращается в исходное положение с анимацией.*/

import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    minimumWidth: 640
    minimumHeight: 480
    visible: true
    title: "Make transition"

    Rectangle {
        id: scene
        anchors.fill: parent
        state: "InitialState"

        Rectangle {
            id: leftRectangle
            x: 100
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5
            //
            Text {
                anchors.centerIn: parent
                text: "move"
            }

            //
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    ball.x += 20
                    if (ball.x + ball.width >= rightRectangle.x || ball.x >= rightRectangle.x + rightRectangle.width/2) {
                        scene.state = "InitialState"
                    } else {
                        scene.state = "OtherState"
                    }
                }
            }
        }

        Rectangle {
            id: rightRectangle
            x: 300
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5
            //
            Text {
                anchors.centerIn: parent
                text: "return"
            }
            //
            MouseArea {
                anchors.fill: parent
                onClicked: scene.state = "InitialState"
            }
        }

        Rectangle {
            id: ball
            color: "darkgreen"
            x: leftRectangle.x + 5
            y: leftRectangle.y + 5
            width: leftRectangle.width - 10
            height: leftRectangle.height - 10
            radius: width / 2
        }

        states: [
            State {
                name: "InitialState"
                PropertyChanges {
                    target: ball
                    x: leftRectangle.x + 5
                }
            },
            State {
                name: "OtherState"
                PropertyChanges {
                    target: ball
                    x: ball.x
                }
            }
        ]

        transitions: [
            Transition {
                from: "OtherState"
                to: "InitialState"

                NumberAnimation {
                    properties: "x,y"
                    duration: 3000
                    easing.type: Easing.OutElastic
                }
            }
        ]
    }
}
