#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
class Bishop : virtual public Piece
{    
public:
    Bishop(Position initialPosition) : Piece(initialPosition){type = PieceType::BISHOP;};
    std::list<Position> getPossibleMovements(const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces) const;

protected:
    void getDiagonalMovements(std::list<Position> & movements, const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces) const;
};


#endif // BISHOP_H
