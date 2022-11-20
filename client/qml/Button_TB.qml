import QtQuick 2.12
import QtQuick.Controls 2.12

Item
{
    id: root
    property alias text: button.text
    property alias checked: button.checked
    property alias checkable: button.checkable
    property alias enabled: button.enabled
    property alias hovered: button.hovered
    property bool hoverEnabled: false

    signal clicked()

    implicitHeight: 60
    implicitWidth: text.implicitWidth + button.__margin

    Button
    {
        id: button
        property var __margin: 20 
        property var __radius: 0
        property var __border: 2

        anchors.fill: root
        hoverEnabled: true
        enabled: true
        checkable: !checked
         
        text: "Button"
        contentItem: Text 
        {
            id:text
            text: button.text
            color: 
            {
                if(button.checked) return "#2c6ad5"
                else if(button.hovered & hoverEnabled) return "#2c6ad5"
                else return "gray"
            }
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }

        background: Rectangle 
        {
            color: 
            {
                if(!button.enabled) return "#333333"
                else if(button.checked) return "#black"
                else return "transparent"
            }

            radius: button.__radius
            border.width: button.__border
            border.color: 
            {
                if(button.checked) return "#2c6ad5"
                else if(button.hovered & hoverEnabled) return "#2c6ad5"
                else return "gray"
            }
        }

        onClicked: root.clicked()
    }
}