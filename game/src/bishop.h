#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
class Bishop : virtual public Piece
{    
public:
    Bishop(Position initialPosition) : Piece(initialPosition){type = PieceType::BISHOP;};
    std::list<Position> getPossibleMovements(const BoardPositions &board) const;

protected:
    std::list<Position> getDiagonalMovements(const BoardPositions &board) const;
};


#endif // BISHOP_H
