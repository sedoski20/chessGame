#include "knight.h"
#include <iostream>

std::list<Position> Knight::getPossibleMovements(const BoardPositions &board) const
{
    std::list<Position> movements;

    movements.push_back(Position(currentPosition.row - 1, currentPosition.column - 2));
    movements.push_back(Position(currentPosition.row + 1, currentPosition.column - 2));

    movements.push_back(Position(currentPosition.row - 1, currentPosition.column + 2));
    movements.push_back(Position(currentPosition.row + 1, currentPosition.column + 2));

    movements.push_back(Position(currentPosition.row - 2, currentPosition.column - 1));
    movements.push_back(Position(currentPosition.row - 2, currentPosition.column + 1));

    movements.push_back(Position(currentPosition.row + 2, currentPosition.column - 1));
    movements.push_back(Position(currentPosition.row + 2, currentPosition.column + 1));

    std::list<Position> result;

    for(Position pos : movements)
    {
        //If has a self piece on position, remove from possible movements
        if(Piece::hasPieceOnPosition(board.getCurrentPlayerPositions(), pos))
            continue;

        //If the position is invalid, remove from possible movements
        if(!(pos.isValidPosition()))
            continue;

        result.push_back(pos);
    }

    return result;
}
