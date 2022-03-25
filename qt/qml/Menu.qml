import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle
{
    Column
    {
        spacing: 5

        Player
        {
            id: player2box
            isPlayer1Box: false
            anchors.left: parent.left
            anchors.leftMargin: 3
        }

        Player
        {
            id: player1box
            isPlayer1Box: true
            anchors.left: parent.left
            anchors.leftMargin: 3
        }
    }
}
