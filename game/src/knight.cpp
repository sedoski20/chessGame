#include "knight.h"
#include <iostream>

std::list<Position> Knight::getPossibleMovements(const BoardPositions &board) const
{
    std::list<Position> movements;
    Position current_position = this->getPosition();
    movements.push_back(Position(current_position.row - 1, current_position.column - 2));
    movements.push_back(Position(current_position.row + 1, current_position.column - 2));

    movements.push_back(Position(current_position.row - 1, current_position.column + 2));
    movements.push_back(Position(current_position.row + 1, current_position.column + 2));

    movements.push_back(Position(current_position.row - 2, current_position.column - 1));
    movements.push_back(Position(current_position.row - 2, current_position.column + 1));

    movements.push_back(Position(current_position.row + 2, current_position.column - 1));
    movements.push_back(Position(current_position.row + 2, current_position.column + 1));

    std::list<Position> result;

    for(Position pos : movements)
    {
        //If has a self piece on position, remove from possible movements
        if(Position::find(board.getCurrentPlayerPositions(), pos))
            continue;

        //If the position is invalid, remove from possible movements
        if(!(pos.isValidPosition()))
            continue;

        result.push_back(pos);
    }

    return result;
}
