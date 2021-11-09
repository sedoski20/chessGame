#include "boardmodel.h"
#include <QQmlEngine>

BoardModel::BoardModel(IGame *game)
{
    squares.clear();


    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            squares.append(new SquareModel(i,j));
        }
    }

    this->i_game = game;
    resetSquares();
    updatePieces();
}

BoardModel::~BoardModel()
{

}

QObject *BoardModel::findSquare(int row, int column) const
{
    for(int i = 0;  i < squares.size(); i++ )
    {
        if(squares.at(i)->getRow() == row && squares.at(i)->getColumn() == column)
        {
            QQmlEngine::setObjectOwnership(squares.at(i), QQmlEngine::CppOwnership);
            return squares.at(i);
        }
    }

    return nullptr;
}

QObject *BoardModel::findSquare(int index) const
{
    for(int i = 0;  i < squares.size(); i++ )
    {
        if(squares.at(i)->getIndex() == index)
        {
            QQmlEngine::setObjectOwnership(squares.at(i), QQmlEngine::CppOwnership);
            return squares.at(i);
        }
    }

    return nullptr;
}

void BoardModel::reset()
{

}

void BoardModel::setIsPlayer1Turn(bool value)
{
    if(this->isPlayer1Turn == value)
        return;

    this->isPlayer1Turn = value;
    emit isPlayer1TurnChanged();
}

bool BoardModel::getIsPlayer1Turn()
{
    return this->isPlayer1Turn;
}

bool BoardModel::select(int index)
{
    SquareModel *square = dynamic_cast<SquareModel*>(findSquare(index));
    i_game->selectPosition(Position(square->getRow(), square->getColumn()));

    std::list<PositionStatus> highlighteds = i_game->getBoardStatus();

    resetSquares();

    for(auto &position : highlighteds)
    {
        square = dynamic_cast<SquareModel*>(findSquare(position.position.row, position.position.column));
        square->setIsHighlited(true);
    }

    updatePieces();
    setIsPlayer1Turn(i_game->isPlayer1Turn());

    return true;
}


void BoardModel::updatePieces()
{
    std::list<PieceInfo> player1 = i_game->getPlayer1Pieces();
    std::list<PieceInfo> player2 = i_game->getPlayer2Pieces();

    for(PieceInfo piece : player1)
    {
        int row = piece.position.row;
        int column = piece.position.column;

        SquareModel *square = dynamic_cast<SquareModel*>(findSquare(row, column));

        if(square != nullptr)
        {
            QString path = getPiecePath(piece.type, true);
            square->setIconPath(path);
        }
    }

    for(PieceInfo piece : player2)
    {
        int row = piece.position.row;;
        int column = piece.position.column;;

        SquareModel *square = dynamic_cast<SquareModel*>(findSquare(row, column));

        if(square != nullptr)
        {
            QString path = getPiecePath(piece.type, false);
            square->setIconPath(path);
        }
    }
}

void BoardModel::resetSquares()
{
    for(int i = 0;  i < squares.size(); i++ )
    {
        squares.at(i)->setIsHighlited(false);
        squares.at(i)->setIconPath("");
    }
}

QString BoardModel::getPiecePath(PieceType type, bool isPlayer1)
{
    QString path = "";

    switch (type)
    {
        case PieceType::PAWN:   path = (isPlayer1) ? "/images/white_pawn.png" : "/images/black_pawn.png"; break;
        case PieceType::ROOK:   path = (isPlayer1) ? "/images/white_rook.png" : "/images/black_rook.png"; break;
        case PieceType::KNIGHT: path = (isPlayer1) ? "/images/white_knight.png" : "/images/black_knight.png"; break;
        case PieceType::BISHOP: path = (isPlayer1) ? "/images/white_bishop.png" : "/images/black_bishop.png"; break;
        case PieceType::QUEEN:  path = (isPlayer1) ? "/images/white_queen.png" : "/images/black_queen.png"; break;
        case PieceType::KING:   path = (isPlayer1) ? "/images/white_king.png" : "/images/black_king.png"; break;
        default: break;
    }

    return path;
}




