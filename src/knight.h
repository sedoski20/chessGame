#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : virtual public Piece
{
private:

public:
    Knight(Position initialPosition) : Piece(initialPosition){};
    std::vector<Position> getPossibleMovements(const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces);
};



#endif // KNIGHT_H
