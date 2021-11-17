import QtQuick 2.0

Rectangle
{
    id:square

    property int row: boardModel.findSquare(index).row
    property int column: boardModel.findSquare(index).column
    property bool highlited: boardModel.findSquare(index).isHighlited


    width: board.width/8
    height: board.height/8

    color: (boardModel.findSquare(index).isBlack) ? "#cfcfcf" : "white"

    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            //Call on selected position on game
            boardModel.select(index)
        }
    }

    Rectangle
    {
        id: highLight
        width: square.width
        height: square.height
        opacity: 0.8
        visible: boardModel.findSquare(index).isHighlited
        color: (boardModel.findSquare(index).isAttack) ? "#b32e3d" : "#f89434"
        z: 1
    }

    Image
    {
        visible: boardModel.findSquare(index).isBlack
        width: square.width
        height: square.height
        anchors.horizontalCenter: square.horizontalCenter
        anchors.verticalCenter: square.verticalCenter
        source: "/images/black_square.jfif"
        opacity: 0.5

    }

    Image
    {
        anchors.horizontalCenter: square.horizontalCenter
        anchors.verticalCenter: square.verticalCenter
        id: pieceImage
        source: boardModel.findSquare(index).iconPath
        z: 2
    }

}
