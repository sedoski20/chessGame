#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include "rook.h"
#include "bishop.h"

class Queen : public Rook, public Bishop
{
public:
    Queen(Position initialPosition) : Rook(initialPosition), Bishop(initialPosition), Piece(initialPosition){};
    std::vector<Position> getPossibleMovements(const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces);
private:

};


#endif // QUEEN_H
