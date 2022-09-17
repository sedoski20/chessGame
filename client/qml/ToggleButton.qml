import QtQuick 2.12
import QtQuick.Controls 2.12


Rectangle
{
    property alias option1: button1.text
    property alias option2: button2.text
    property bool option1Enabled: true
    property bool option2Enabled: true
    property bool firstSelected: option1Enabled
    property bool hovered: button1.hovered + button2.hovered
    signal stateChanged()


    id: toggle_button
    color: "transparent"
    implicitWidth: button1.implicitWidth + button2.implicitWidth
    implicitHeight: 60

    Row
    {
        id: row
        anchors.fill: parent
        property var gap: 4

        property var max_width: (width / 2) - (gap / 2)
        
        Button_TB
        {
            id: button1
            text: "Button1"
            enabled: toggle_button.option1Enabled
            width: row.max_width
            height: row.height
            checked: toggle_button.firstSelected

            onClicked: 
            {
                toggle_button.firstSelected = true
                toggle_button.stateChanged()
            }
        }

        Rectangle
        {
            color: "transparent"
            height: row.height
            width: 4
        }

        Button_TB
        {
            id: button2
            text: "Button2"
            enabled: toggle_button.option2Enabled
            width: row.max_width
            height: row.height
            checked: !toggle_button.firstSelected

            onClicked: 
            {
                toggle_button.firstSelected = false
                toggle_button.stateChanged()
            }
        }
    }
}
