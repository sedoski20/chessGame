#include "king.h"

std::list<Position> King::getPossibleMovements(const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces) const
{
    std::list<Position> movements;
    getVerticalMovements(movements, selfPieces, opponentPieces);
    getHorizontalMovements(movements, selfPieces, opponentPieces);
    getDiagonalMovements(movements, selfPieces, opponentPieces);

    return movements;
}

void King::getDiagonalMovements(std::list<Position> & movements, const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces) const
{
    int row = this->currentPosition.row;
    int colunm = this->currentPosition.column;

    Position pos = Position(row + 1, colunm + 1);
    
    if(pos.isValidPosition() && !Piece::hasPieceOnPosition(selfPieces, pos))
        movements.push_back(pos);

    pos = Position(row + 1, colunm - 1);

    if(pos.isValidPosition() && !Piece::hasPieceOnPosition(selfPieces, pos))
        movements.push_back(pos);

    pos = Position(row - 1, colunm + 1);

    if(pos.isValidPosition() && !Piece::hasPieceOnPosition(selfPieces, pos))
        movements.push_back(pos);

     pos = Position(row - 1, colunm - 1);

    if(pos.isValidPosition() && !Piece::hasPieceOnPosition(selfPieces, pos))
        movements.push_back(pos);
    
}

void King::getHorizontalMovements(std::list<Position> & movements, const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces) const
{
    int row = this->currentPosition.row;
    int colunm = this->currentPosition.column;

    Position pos = Position(row, colunm + 1);
    
    if(pos.isValidPosition() && !Piece::hasPieceOnPosition(selfPieces, pos))
        movements.push_back(pos);

    pos = Position(row, colunm - 1);

    if(pos.isValidPosition() && !Piece::hasPieceOnPosition(selfPieces, pos))
        movements.push_back(pos);
    
}

void King::getVerticalMovements(std::list<Position> & movements, const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces) const
{
    int row = this->currentPosition.row;
    int colunm = this->currentPosition.column;

    Position pos = Position(row + 1, colunm);
    
    if(pos.isValidPosition() && !Piece::hasPieceOnPosition(selfPieces, pos))
        movements.push_back(pos);

    pos = Position(row - 1, colunm);

    if(pos.isValidPosition() && !Piece::hasPieceOnPosition(selfPieces, pos))
        movements.push_back(pos);
}
