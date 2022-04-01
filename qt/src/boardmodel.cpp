#include "boardmodel.h"
#include <QQmlEngine>
#include "boardstatus.h"

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

     setIsPlayer1Turn(true);
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

void BoardModel::setIsGameEnded(bool value)
{
    if(this->isGameEnded == value)
        return;

    this->isGameEnded = value;
    emit isGameEndedChanged();
}

bool BoardModel::getIsPlayer1Turn()
{
    return this->isPlayer1Turn;
}

bool BoardModel::getIsGameEnded()
{
    return this->isGameEnded;
}

bool BoardModel::select(int index)
{
    SquareModel *square = dynamic_cast<SquareModel*>(findSquare(index));
    i_game->selectPosition(Position(square->getRow(), square->getColumn()));

    std::list<PositionStatus> board_status = i_game->getBoardStatus().getHighlightedPositions();

    resetSquares();

    for(auto &status : board_status)
    {
        square = dynamic_cast<SquareModel*>(findSquare(status.getPosition().row, status.getPosition().column));
        square->setIsHighlited(true);

        if(status.getStatus() == Status::ATTACK || status.getStatus() == Status::CHECK)
            square->setIsAttack(true);
    }

    updatePieces();
    // setIsPlayer1Turn(i_game->isPlayer1Turn());

    GameStatus status = i_game->getGameStatus();
    setIsGameEnded((status == GameStatus::ENDED) ? true : false);

    return true;
}


void BoardModel::updatePieces()
{
    std::list<const Piece*> player1 = i_game->getBoardStatus().getPlayer1Pieces();
    std::list<const Piece*> player2 = i_game->getBoardStatus().getPlayer2Pieces();

    for(auto piece : player1)
    {
        int row = piece->getPosition().row;
        int column = piece->getPosition().column;

        SquareModel *square = dynamic_cast<SquareModel*>(findSquare(row, column));

        if(square != nullptr)
        {
            QString path = getPiecePath(piece->getType(), true);
            square->setIconPath(path);
        }
    }

    for(auto piece : player2)
    {
        int row = piece->getPosition().row;
        int column = piece->getPosition().column;

        SquareModel *square = dynamic_cast<SquareModel*>(findSquare(row, column));

        if(square != nullptr)
        {
            QString path = getPiecePath(piece->getType(), false);
            square->setIconPath(path);
        }
    }
}

void BoardModel::resetSquares()
{
    for(int i = 0;  i < squares.size(); i++ )
    {
        squares.at(i)->setIsHighlited(false);
        squares.at(i)->setIsAttack(false);
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




