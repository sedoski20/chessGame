#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : virtual public Piece
{
public:
    Rook(Position initialPosition) : Piece(initialPosition){type = PieceType::ROOK;};
    std::list<Position> getPossibleMovements(const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces);

protected:
    void getHorizontalMovements(std::list<Position> & movements, const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces);
    void getVerticalMovements(std::list<Position> & movements, const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces);
    
};

#endif // ROOK_H
