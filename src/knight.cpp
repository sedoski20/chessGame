#include "knight.h"
#include <iostream>

std::vector<Position> Knight::getPossibleMovements(const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces) 
{
    std::vector<Position> movements;

    movements.push_back(Position(currentPosition.row - 1, currentPosition.column - 2));
    movements.push_back(Position(currentPosition.row + 1, currentPosition.column - 2));

    movements.push_back(Position(currentPosition.row - 1, currentPosition.column + 2));
    movements.push_back(Position(currentPosition.row + 1, currentPosition.column + 2));

    movements.push_back(Position(currentPosition.row - 2, currentPosition.column - 1));
    movements.push_back(Position(currentPosition.row - 2, currentPosition.column + 1));

    movements.push_back(Position(currentPosition.row + 2, currentPosition.column - 1));
    movements.push_back(Position(currentPosition.row + 2, currentPosition.column + 1));

    std::vector<Position> result;

    //Gets an iterator for each element in the list
    for(int i = 0; i < movements.size(); i++)
    {
        Position pos = movements.at(i);

        //If has a self piece on position, remove from possible movements
        if(Piece::hasPieceOnPosition(selfPieces, pos))
            continue;

        //If the position is invalid, remove from possible movements
        if(!(pos.isValidPosition()))
            continue;

        result.push_back(pos);
    }

    return result;
}
