#include "bishop.h"

enum class bishopMovements
{
    RIGHT_ABOVE,
    LEFT_BELOW,
    LEFT_ABOVE,
    RIGHT_BELOW
};

std::list<Position> Bishop::getPossibleMovements(const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces) const
{
      std::list<Position> movements;
      getDiagonalMovements(movements, selfPieces, opponentPieces);
      return movements;
}

void Bishop::getDiagonalMovements(std::list<Position> & movements, const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces) const
{
    for(int i = 0; i < 4; i++)
    {
        Position position(currentPosition.row, currentPosition.column);
        bishopMovements sequence = static_cast<bishopMovements>(i);

        //Look from the current position to left above, stop if some self piece or opponnent is on the position
        do
        {
            switch(sequence)
            {
                case bishopMovements::RIGHT_ABOVE:  position.row++; position.column++; break;
                case bishopMovements::LEFT_BELOW:   position.row--; position.column--; break;
                case bishopMovements::LEFT_ABOVE:   position.row++; position.column--; break;
                case bishopMovements::RIGHT_BELOW:  position.row--; position.column++; break;
            }

            if(!position.isValidPosition())
                break;

            //is some self piece on position?
            if(Piece::hasPieceOnPosition(selfPieces, position))
                break;

            movements.push_back(position);

            //is some opponent piece on position?
            if(Piece::hasPieceOnPosition(opponentPieces, position))
                break;
        }
        while(position.isValidPosition());    
    }
}
