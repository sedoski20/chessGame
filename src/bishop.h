#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
class Bishop : public Piece
{    
public:
    Bishop(Position initialPosition) : Piece(initialPosition){};
    std::vector<Position> getPossibleMovements(const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces);

private:
    void getDiagonalMovements(std::vector<Position> & movements, const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces);
};


#endif // BISHOP_H
