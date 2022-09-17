import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0
 
Rectangle
{
    id: root
    width: 1200
    height: 800
    visible: true

    color: "#1e1e1e"

    property bool finished: false

    Rectangle
    {
        id: topHeader
        color: "#1e1e1e"

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: 0.1 * parent.height

        Text
        {
            font.family: "Ubuntu"
            text: "New Game"
            color: "lightgray"
            font.pixelSize: 50

            anchors
            {
                verticalCenter: parent.verticalCenter
                left: parent.left
                leftMargin: 20
            }
        }
    }

    ToggleButton
    {
        id: mode_button
        option1: "SinglePlayer"
        option2: "MultiPlayer"
        option1Enabled: false 
        
        anchors
        {
            top: topHeader.bottom
            left:topHeader.left
            right: topHeader.right
            margins: 20
        }
    }

    Rectangle
    {
        id: multiplayer_group
        color: "#333333"
        radius: 20

        anchors
        {
            top: mode_button.bottom
            bottom: start_buttom.top
            left: mode_button.left
            right: mode_button.horizontalCenter
            topMargin: 20
            bottomMargin: 20

        }
        

        Grid
        {
            anchors.fill: parent
            anchors.margins: 30

            columns: 2
            rows: 4
            id: grid
            spacing: 30
            verticalItemAlignment: Grid.AlignVCenter
            property var textFieldFontSize: 14
            property var labelFontSize: 14
        
            Text { text: "Game Mode"; font.pointSize: parent.labelFontSize; color:  game_mode.hovered ? "#2c6ad5" :"gray" }
            ToggleButton { option1: "Offline"; option2: "Online"; id: game_mode; width: 300; onStateChanged: mainMenuModel.gameMode = firstSelected}

            Text { text: "Player 1 Name "; font.pointSize: grid.labelFontSize; color: player1.hovered ? "#2c6ad5" :"gray" }
            TextField { placeholderText: "Marcelo"; font.pointSize: grid.textFieldFontSize; width: 300; id: player1; onTextChanged: mainMenuModel.player1 = text}

            Text { text: "Player 2 Name "; font.pointSize: grid.labelFontSize; color: player2.hovered ? "#2c6ad5" :"gray" }
            TextField { placeholderText: "Flavia"; font.pointSize: grid.textFieldFontSize; width: 300 ; id: player2; onTextChanged: mainMenuModel.player2 = text}

            Text { text: "Server Address"; font.pointSize: grid.labelFontSize; visible: !game_mode.firstSelected; color: address.hovered ? "#2c6ad5" :"gray"}
            TextField { placeholderText: "172.45.123.66"; font.pointSize: grid.textFieldFontSize; visible: !game_mode.firstSelected; width: 300; id: address; onTextChanged: mainMenuModel.serverAddress = text}

        }
    }


    Button_TB
    {
        id: start_buttom
        height: 50
        text: "Start"
        hoverEnabled: true

        anchors
        {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            margins: 20
        }

        onClicked: 
        {
            root.finished = true
            mainMenuModel.start()
        }
    }
}