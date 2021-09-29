#include "rook.h"
#include <iostream>
        
std::vector<Position> Rook::getPossibleMovements(const std::vector<Position>& selfPieces, 
                                const std::vector<Position>& opponentPieces) 
{
    std::vector<Position> movements;
    this->getHorizontalMovements(movements, selfPieces, opponentPieces);
    this->getVerticalMovements(movements, selfPieces, opponentPieces);

    return movements;
}

void Rook::getHorizontalMovements(std::vector<Position>& movements, 
                                const std::vector<Position>& selfPieces, 
                                const std::vector<Position>& opponentPieces) 
{
    //Look from the current position to left, stop if some self piece or opponnent is on the position
    for(int i = currentPosition.column - 1; i >= 0; i--)
    {
        Position position(currentPosition.row, i);

        //is some self piece on position?
        if(Piece::hasPieceOnPosition(selfPieces, position))
            break;

        movements.push_back(position);

        //is some opponent piece on position?
        if(Piece::hasPieceOnPosition(opponentPieces, position))
            break;
    }

    //Look from the current position to right, stop if some self piece or opponnent is on the position
    for(int i = currentPosition.column + 1; i <= 7; i++)
    {
        Position position(currentPosition.row, i);

        //is some self piece on position?
        if(Piece::hasPieceOnPosition(selfPieces, position))
            break;

        movements.push_back(position);

        //is some opponent piece on position?
        if(Piece::hasPieceOnPosition(opponentPieces, position))
            break;
    }
}

void Rook::getVerticalMovements(std::vector<Position>& movements, 
                                const std::vector<Position>& selfPieces, 
                                const std::vector<Position>& opponentPieces) 
{
    //Look from the current position to bottom, stop if some self piece or opponnent is on the position
    for(int i = currentPosition.row - 1; i >= 0; i--)
    {
        Position position(i, currentPosition.column);

        //is some self piece on position?
        if(Piece::hasPieceOnPosition(selfPieces, position))
            break;

        movements.push_back(position);

        //is some opponent piece on position?
        if(Piece::hasPieceOnPosition(opponentPieces, position))
            break;
    }

    //Look from the current position to right, stop if some self piece or opponnent is on the position
    for(int i = currentPosition.row + 1; i <= 7; i++)
    {
        Position position(i, currentPosition.column);

        //is some self piece on position?
        if(Piece::hasPieceOnPosition(selfPieces, position))
            break;

        movements.push_back(position);

        //is some opponent piece on position?
        if(Piece::hasPieceOnPosition(opponentPieces, position))
            break;
    }
}
 