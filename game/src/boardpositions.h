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
    BoardPositions(const std::list<Position> &currentPlayerPositions,
                   const std::list<Position> &opponentPlayerPositions);

    const std::list<Position> getCurrentPlayerPositions() const { return currentPlayerPositions; };
    const std::list<Position> getOpponentPlayerPositions() const { return opponentPlayerPositions; };
};

#endif // BOARDPOSITIONS_H
