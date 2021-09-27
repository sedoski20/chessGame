#include "rook.h"
#include <iostream>

Rook::Rook(Position initialPosition)
{
    this->currentPosition = initialPosition;
    //TODO: Check if some iniatialization is need
}

std::vector<Position> Rook::getPossibleMovements(const std::vector<Position>& selfPieces, 
                                const std::vector<Position>& opponentPieces) 
{
    std::vector<Position> movements;
    this->getHorizontalMovements(movements, selfPieces, opponentPieces);
}

void Rook::getHorizontalMovements(std::vector<Position>& movements, 
                                const std::vector<Position>& selfPieces, 
                                const std::vector<Position>& opponentPieces) 
{
    for(int i = currentPosition.column; i > 0; --i)
    {
        std::cout << "Coluna: " << i;
    }
}

void Rook::getVerticalMovements(std::vector<Position>& movements, 
                                const std::vector<Position>& selfPieces, 
                                const std::vector<Position>& opponentPieces) 
{
    
}
 