#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
class Bishop : virtual public Piece
{    
public:
    Bishop(Position initialPosition) : Piece(initialPosition){type = PieceType::BISHOP;};
    std::vector<Position> getPossibleMovements(const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces);

protected:
    void getDiagonalMovements(std::vector<Position> & movements, const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces);
};


#endif // BISHOP_H
