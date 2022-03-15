#ifndef KING_H
#define KING_H

#include "piece.h"
class King : public Piece
{
public:
    King(Position initialPosition) : Piece(initialPosition){type = PieceType::KING;};
    std::list<Position> getPossibleMovements(const BoardPositions &board) const;

private:
    std::list<Position> getDiagonalMovements(const BoardPositions &board) const;
    std::list<Position> getHorizontalMovements(const BoardPositions &board) const;
    std::list<Position> getVerticalMovements(const BoardPositions &board) const;
};

#endif // KING_H
