#include "queen.h"

std::list<Position> Queen::getPossibleMovements(const BoardPositions &board) const
{
    std::list<Position> movements;
    movements.merge(getHorizontalMovements(board));
    movements.merge(getVerticalMovements(board));
    movements.merge(getDiagonalMovements(board));

    return movements;
}
