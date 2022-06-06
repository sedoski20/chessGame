#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : virtual public Piece
{
private:

public:
    Knight(Position initialPosition) : Piece(initialPosition, PieceType::KNIGHT){};
    std::list<Position> getPossibleMovements(const BoardPositions &board) const;
};

#endif // KNIGHT_H
