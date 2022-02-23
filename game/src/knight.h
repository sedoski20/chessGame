#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : virtual public Piece
{
private:

public:
    Knight(Position initialPosition) : Piece(initialPosition){type = PieceType::KNIGHT;};
    std::list<Position> getPossibleMovements(const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces);
};



#endif // KNIGHT_H
