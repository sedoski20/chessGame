#include "queen.h"

std::vector<Position> Queen::getPossibleMovements(const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces) 
{
    std::vector<Position> movements;
    this->getHorizontalMovements(movements, selfPieces, opponentPieces);
    this->getVerticalMovements(movements, selfPieces, opponentPieces);
    this->getDiagonalMovements(movements, selfPieces, opponentPieces);

    return movements;
}
