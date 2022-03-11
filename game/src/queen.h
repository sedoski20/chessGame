#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include "rook.h"
#include "bishop.h"

class Queen : public Rook, public Bishop
{
public:
    Queen(Position initialPosition) : Rook(initialPosition), Bishop(initialPosition), Piece(initialPosition){type = PieceType::QUEEN;};
    std::list<Position> getPossibleMovements(const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces);
private:

};


#endif // QUEEN_H
