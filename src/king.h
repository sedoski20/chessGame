#ifndef KING_H
#define KING_H

#include "piece.h"
class King : public Piece
{
public:
    King(Position initialPosition) : Piece(initialPosition){};
    std::vector<Position> getPossibleMovements(const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces);

private:
    void getDiagonalMovements(std::vector<Position> & movements, const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces);
    void getHorizontalMovements(std::vector<Position> & movements, const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces);
    void getVerticalMovements(std::vector<Position> & movements, const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces);
};

#endif // KING_H
