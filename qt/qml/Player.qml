import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle
{
    id: playerBox
    property bool isPlayer1Box
    property bool currentTurn: (!(boardModel.isPlayer1Turn ^ isPlayer1Box))
    

    width: lateralMenu.width - 6
    height: (lateralMenu.height/2) - 4
    color: currentTurn ? "#4db34d" : "gray"
    border.color: "black"
    border.width: 1
    radius: 10
    opacity: (currentTurn) ? 0.7 : 0.5

    TextField
    {
        id: playerTitle
        
        property var textPlayer: (isPlayer1Box) ? "Player 1" : "Player 2"
        placeholderText: playerTitle.focus ? "" : textPlayer
        placeholderTextColor: currentTurn ? "#0f240f" : "black"
        font.pointSize: 24
        color: currentTurn ? "#0f240f" : "black"

        anchors.left: playerBox.left
        anchors.top: playerBox.top
        anchors.right: playerBox.right
        anchors.leftMargin: 6
        anchors.topMargin: 6
        anchors.rightMargin: 6

        background: Rectangle
        {
            implicitWidth: 100
            implicitHeight: 50
            color: "transparent"
            border.color: (playerTitle.activeFocus || playerTitle.hovered) ? "#0f240f" : "transparent"
        }
    }
}
