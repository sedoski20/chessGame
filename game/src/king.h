#ifndef KING_H
#define KING_H

#include "piece.h"
class King : public Piece
{
public:
    King(Position initialPosition) : Piece(initialPosition){type = PieceType::KING;};
    std::list<Position> getPossibleMovements(const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces);

private:
    void getDiagonalMovements(std::list<Position> & movements, const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces);
    void getHorizontalMovements(std::list<Position> & movements, const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces);
    void getVerticalMovements(std::list<Position> & movements, const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces);
};

#endif // KING_H
