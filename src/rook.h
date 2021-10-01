#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : virtual public Piece
{
public:
    Rook(Position initialPosition) : Piece(initialPosition){};
    std::vector<Position> getPossibleMovements(const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces);

private:
    void getHorizontalMovements(std::vector<Position> & movements, const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces);
    void getVerticalMovements(std::vector<Position> & movements, const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces);
    
};

#endif // ROOK_H
