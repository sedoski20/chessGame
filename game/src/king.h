#ifndef KING_H
#define KING_H

#include "piece.h"
class King : public Piece
{
public:
    King(Position initialPosition) : Piece(initialPosition){type = PieceType::KING;};
    std::list<Position> getPossibleMovements(const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces) const;

private:
    void getDiagonalMovements(std::list<Position> & movements, const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces) const;
    void getHorizontalMovements(std::list<Position> & movements, const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces) const;
    void getVerticalMovements(std::list<Position> & movements, const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces) const;
};

#endif // KING_H
