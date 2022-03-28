#include "king.h"

std::list<Position> King::getPossibleMovements(const BoardPositions &board) const
{
    std::list<Position> movements;
    movements.merge(getVerticalMovements(board));
    movements.merge(getHorizontalMovements(board));
    movements.merge(getDiagonalMovements(board));

    return movements;
}

std::list<Position> King::getDiagonalMovements(const BoardPositions &board) const
{
    std::list<Position> movements;
    int row = this->position.row;
    int colunm = this->position.column;

    Position pos = Position(row + 1, colunm + 1);
    
    if(pos.isValidPosition() && !Position::find(board.getCurrentPlayerPositions(), pos))
        movements.push_back(pos);

    pos = Position(row + 1, colunm - 1);

    if(pos.isValidPosition() && !Position::find(board.getCurrentPlayerPositions(), pos))
        movements.push_back(pos);

    pos = Position(row - 1, colunm + 1);

    if(pos.isValidPosition() && !Position::find(board.getCurrentPlayerPositions(), pos))
        movements.push_back(pos);

     pos = Position(row - 1, colunm - 1);

    if(pos.isValidPosition() && !Position::find(board.getCurrentPlayerPositions(), pos))
        movements.push_back(pos);

    return movements;
}

std::list<Position> King::getHorizontalMovements(const BoardPositions &board) const
{
    std::list<Position> movements;
    int row = this->position.row;
    int colunm = this->position.column;

    Position pos = Position(row, colunm + 1);

    if(pos.isValidPosition() && !Position::find(board.getCurrentPlayerPositions(), pos))
        movements.push_back(pos);

    pos = Position(row, colunm - 1);

    if(pos.isValidPosition() && !Position::find(board.getCurrentPlayerPositions(), pos))
        movements.push_back(pos);

    return movements;
}

std::list<Position> King::getVerticalMovements(const BoardPositions &board) const
{
    std::list<Position> movements;
    int row = this->position.row;
    int colunm = this->position.column;

    Position pos = Position(row + 1, colunm);
    
    if(pos.isValidPosition() && !Position::find(board.getCurrentPlayerPositions(), pos))
        movements.push_back(pos);

    pos = Position(row - 1, colunm);

    if(pos.isValidPosition() && !Position::find(board.getCurrentPlayerPositions(), pos))
        movements.push_back(pos);

    return movements;
}
