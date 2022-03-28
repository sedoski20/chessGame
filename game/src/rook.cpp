#include "rook.h"
#include <iostream>
        
std::list<Position> Rook::getPossibleMovements(const BoardPositions &board) const
{
    std::list<Position> movements;
    movements.merge(getHorizontalMovements(board));
    movements.merge(getVerticalMovements(board));

    return movements;
}

std::list<Position> Rook::getHorizontalMovements(const BoardPositions &board) const
{
    std::list<Position> movements;
    //Look from the current position to left, stop if some self piece or opponnent is on the position
    for(int i = this->position.column - 1; i >= 0; i--)
    {
        Position position(this->position.row, i);

        //is some self piece on position?
        if(Position::find(board.getCurrentPlayerPositions(), position))
            break;

        movements.push_back(position);

        //is some opponent piece on position?
        if(Position::find(board.getOpponentPlayerPositions(), position))
            break;
    }

    //Look from the current position to right, stop if some self piece or opponnent is on the position
    for(int i = this->position.column + 1; i <= 7; i++)
    {
        Position position(this->position.row, i);

        //is some self piece on position?
        if(Position::find(board.getCurrentPlayerPositions(), position))
            break;

        movements.push_back(position);

        //is some opponent piece on position?
        if(Position::find(board.getOpponentPlayerPositions(), position))
            break;
    }

    return movements;
}

std::list<Position> Rook::getVerticalMovements(const BoardPositions &board) const
{
    std::list<Position> movements;
    //Look from the current position to bottom, stop if some self piece or opponnent is on the position
    for(int i = this->position.row - 1; i >= 0; i--)
    {
        Position position(i, this->position.column);

        //is some self piece on position?
        if(Position::find(board.getCurrentPlayerPositions(), position))
            break;

        movements.push_back(position);

        //is some opponent piece on position?
        if(Position::find(board.getOpponentPlayerPositions(), position))
            break;
    }

    //Look from the current position to top, stop if some self piece or opponnent is on the position
    for(int i = this->position.row + 1; i <= 7; i++)
    {
        Position position(i, this->position.column);

        //is some self piece on position?
        if(Position::find(board.getCurrentPlayerPositions(), position))
            break;

        movements.push_back(position);

        //is some opponent piece on position?
        if(Position::find(board.getOpponentPlayerPositions(), position))
            break;
    }

    return movements;
}
 