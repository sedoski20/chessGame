#include "bishop.h"

enum class bishopMovements
{
    RIGHT_ABOVE,
    LEFT_BELOW,
    LEFT_ABOVE,
    RIGHT_BELOW
};

std::list<Position> Bishop::getPossibleMovements(const BoardPositions &board) const
{
      std::list<Position> movements;
      movements.merge(getDiagonalMovements(board));
      return movements;
}

std::list<Position> Bishop::getDiagonalMovements(const BoardPositions &board) const
{
    std::list<Position> movements;
    for(int i = 0; i < 4; i++)
    {
        Position position(this->getPosition().row, this->getPosition().column);
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
            if(Position::find(board.getCurrentPlayerPositions(), position))
                break;

            movements.push_back(position);

            //is some opponent piece on position?
            if(Position::find(board.getOpponentPlayerPositions(), position))
                break;
        }
        while(position.isValidPosition());    
    }

    return movements;
}
