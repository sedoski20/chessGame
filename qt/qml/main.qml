import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.12

Window
{
    id: window
    width: 800
    height: 600
    title: "ChessGame"
    visible: true

    Rectangle
    {
        id: main
        width: window.width
        height: window.height
        anchors.centerIn: parent
    }

    Menu {}

    Rectangle
    {
        id: board
        width: main.width - 200
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
                Square {}
            }
        }
    }
}







