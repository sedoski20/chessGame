#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : virtual public Piece
{
public:
    Rook(Position initialPosition) : Piece(initialPosition, PieceType::ROOK){};
    ~Rook() {};
    std::list<Position> getPossibleMovements(const BoardPositions &board) const;

protected:
    std::list<Position> getHorizontalMovements(const BoardPositions &board) const;
    std::list<Position> getVerticalMovements(const BoardPositions &board) const; 
};

#endif // ROOK_H
