import QtQuick 2.0

Rectangle
{
    id:square

    property int row: boardModel.findSquare(index).row
    property int column: boardModel.findSquare(index).column
    property bool highlited: boardModel.findSquare(index).isHighlited


    width: board.width/8
    height: board.height/8

    color: (boardModel.findSquare(index).isBlack) ? "#80232D" : "#FCFCEF"

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
        color: "#f89434"
    }

    Image
    {
        anchors.horizontalCenter: square.horizontalCenter
        anchors.verticalCenter: square.verticalCenter
        id: pieceImage
        source: boardModel.findSquare(index).iconPath
    }

}
