import QtQuick 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle
{
    id: lateralMenu
    color: "gray"
    width: 200

    height: main.height
    anchors.right: main.right

    Column
    {
        spacing: 2
        anchors.centerIn: parent
        Rectangle
        {
            width: lateralMenu.width - 6
            height: (lateralMenu.height/2) - 4
            color: (boardModel.isPlayer1Turn) ? "gray" : "#DD838E"
            border.color: "black"
            border.width: 2
            opacity: (boardModel.isPlayer1Turn) ? 0.5 : 1

            Text
            {
                id: player2Title
                text: "Player 2"
                font.pointSize: 24
                leftPadding: 10
                color: (boardModel.isPlayer1Turn) ? "black" : "#80232D"
            }
        }

        Rectangle
        {
            width: lateralMenu.width - 6
            height: (lateralMenu.height/2) - 4
            color: (boardModel.isPlayer1Turn) ? "#DD838E" : "gray"
            border.color: "black"
            border.width: 2
            opacity: (boardModel.isPlayer1Turn) ? 1 : 0.5

            Text
            {
                id: player1Title
                text: "Player 1"
                font.pointSize: 24
                leftPadding: 10
                color: (boardModel.isPlayer1Turn) ? "#80232D" : "black"
            }
        }
    }
}
