#include "queen.h"

std::list<Position> Queen::getPossibleMovements(const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces) const
{
    std::list<Position> movements;
    this->getHorizontalMovements(movements, selfPieces, opponentPieces);
    this->getVerticalMovements(movements, selfPieces, opponentPieces);
    this->getDiagonalMovements(movements, selfPieces, opponentPieces);

    return movements;
}
