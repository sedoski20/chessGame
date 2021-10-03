#include "king.h"

std::vector<Position> King::getPossibleMovements(const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces) 
{
    std::vector<Position> movements;
    getVerticalMovements(movements, selfPieces, opponentPieces);
    getHorizontalMovements(movements, selfPieces, opponentPieces);
    getDiagonalMovements(movements, selfPieces, opponentPieces);

    return movements;
}

void King::getDiagonalMovements(std::vector<Position> & movements, const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces) 
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

void King::getHorizontalMovements(std::vector<Position> & movements, const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces) 
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

void King::getVerticalMovements(std::vector<Position> & movements, const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces) 
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
