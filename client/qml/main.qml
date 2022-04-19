import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0

Window
{
    id: window
    width: 1200
    height: 800
    title: "ChessGame"
    visible: true


    MouseArea
    {
        anchors.fill: parent
        onClicked: focus = true
    }


    Rectangle
    {
        id: main
        width: window.width
        height: window.height
        anchors.centerIn: parent
    }

    Menu
    {
        id: lateralMenu
        color: "white"
        height: main.height
        anchors.right: main.right
        anchors.left: board.right
        anchors.top: main.top
    }

    Rectangle
    {
        id: board
        width: main.height
        height: main.height

        Grid
        {
            columns: 8
            rows: 8
            LayoutMirroring.enabled: true

            Repeater
            {
                id: squares
                model: 64
                Square {z:2}
            }
        }
    }

    Item
    {
        id: status
        anchors.centerIn: board
        visible: boardModel.isGameEnded
        z: 1

        Rectangle
        {
            anchors.centerIn: status
            visible: true
            width: 400
            height: 100
            radius: 50
            color: "#4db34d"
            opacity: 0.8
        }

        Text {
            id: result
            text: boardModel.isPlayer1Turn ? "Player 2 Wins!" : "Player 1 Wins!"
            color: "#0f240f"
            font.pointSize: 40
            anchors.horizontalCenter: status.horizontalCenter
            anchors.verticalCenter: status.verticalCenter
            opacity: 1
        }
    }

    GaussianBlur
    {
        id: statusBlur
        visible: boardModel.isGameEnded
        anchors.fill: board
        source: board
        radius: 15
        samples: 31
    }
}







