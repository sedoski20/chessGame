#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include "rook.h"
#include "bishop.h"

class Queen : public Rook, public Bishop
{
public:
    Queen(Position initialPosition) : Rook(initialPosition), Bishop(initialPosition), Piece(initialPosition){type = PieceType::QUEEN;};
    ~Queen() {};
    std::list<Position> getPossibleMovements(const BoardPositions &board) const;
private:

};


#endif // QUEEN_H
