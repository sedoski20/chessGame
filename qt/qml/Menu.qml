import QtQuick 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle
{
    Rectangle
    {
        id: player2Box
        anchors.top: lateralMenu.top
        anchors.left: lateralMenu.left
        anchors.leftMargin: 3
        anchors.topMargin: 3

        width: lateralMenu.width - 6
        height: (lateralMenu.height/2) - 4
        color: (!boardModel.isPlayer1Turn) ? "#4db34d" : "gray"
        border.color: "black"
        border.width: 1
        radius: 10
        opacity: (!boardModel.isPlayer1Turn) ? 0.7 : 0.5

        TextField
        {
            id: player2Title
            placeholderText: player2Title.focus ? "" : "Player 2"
            placeholderTextColor: (!boardModel.isPlayer1Turn) ? "#0f240f" : "black"
            font.pointSize: 24
            color: (!boardModel.isPlayer1Turn) ? "#0f240f" : "black"

            anchors.left: player2Box.left
            anchors.top: player2Box.top
            anchors.right: player2Box.right
            anchors.leftMargin: 6
            anchors.topMargin: 6
            anchors.rightMargin: 6

            background: Rectangle
            {
                implicitWidth: 100
                implicitHeight: 50
                color: "transparent"
                border.color: (player2Title.activeFocus || player2Title.hovered) ? "#0f240f" : "transparent"
            }

        }
    }

    Rectangle
    {
        id: player1Box
        anchors.bottom: lateralMenu.bottom
        anchors.left: lateralMenu.left
        anchors.leftMargin: 3
        anchors.bottomMargin: 3

        width: lateralMenu.width - 6
        height: (lateralMenu.height/2) - 4
        color: (boardModel.isPlayer1Turn) ? "#4db34d" : "gray"
        border.color: "black"
        border.width: 1
        radius: 10
        opacity: (boardModel.isPlayer1Turn) ? 0.7 : 0.5

        TextField
        {
            id: player1Title
            placeholderText: player1Title.focus ? "" : "Player 1"
            placeholderTextColor: (boardModel.isPlayer1Turn) ? "#0f240f" : "black"
            font.pointSize: 24
            color: (boardModel.isPlayer1Turn) ? "#0f240f" : "black"

            anchors.left: player1Box.left
            anchors.top: player1Box.top
            anchors.right: player1Box.right
            anchors.leftMargin: 6
            anchors.topMargin: 6
            anchors.rightMargin: 6

            background: Rectangle
            {
                implicitWidth: 100
                implicitHeight: 50
                color: "transparent"
                border.color: (player1Title.focus || player1Title.hovered) ? "#0f240f" : "transparent"
            }
        }
    }
}
