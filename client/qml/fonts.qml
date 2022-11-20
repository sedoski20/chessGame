import QtQuick 2.0
import QtQuick.Window 2.11

Window
{
    title: "Fonts"
    visibility: Window.Maximized

    ListView {
        anchors.fill: parent; 
        model: Qt.fontFamilies()

        delegate: Item {
            height: fontText.height + 10; 
            width: ListView.view.width

            Text {
                id: fontText
                anchors.centerIn: parent
                text: modelData;
                font.family: modelData
                font.pointSize: 40
            }
        }
    }
}