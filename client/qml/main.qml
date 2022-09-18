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

    Loader
    {
        id: loader_top
        source: !mainMenuModel.finished ? "MainMenu.qml" : "Game.qml"
    }
}







