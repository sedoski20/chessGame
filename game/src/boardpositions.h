#ifndef BOARDPOSITIONS_H
#define BOARDPOSITIONS_H

#include "position.h"
#include <list>

class BoardPositions
{
private:
    std::list<Position> currentPlayerPositions;
    std::list<Position> opponentPlayerPositions;

public:
    BoardPositions(std::list<Position> currentPlayerPositions,
                   std::list<Position> opponentPlayerPositions) : 
                   currentPlayerPositions(currentPlayerPositions),
                   opponentPlayerPositions(opponentPlayerPositions){};

    const std::list<Position> getCurrentPlayerPositions() const { return currentPlayerPositions; };
    const std::list<Position> getOpponentPlayerPositions() const { return opponentPlayerPositions; };
};

#endif // BOARDPOSITIONS_H
