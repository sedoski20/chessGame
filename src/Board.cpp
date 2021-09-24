#include "Board.h"

std::vector<Position> Board::getAvailablePositionsOnBoard()
{
    return std::vector<Position>();
}

int Board::getValue()
{
    return this->value;
}

void Board::setValue(int value)
{
    this->value = value;
}
