#include "boardpositions.h"

BoardPositions::BoardPositions(const std::list<Position> &currentPlayerPositions,
                               const std::list<Position> &opponentPlayerPositions)
                             : currentPlayerPositions(currentPlayerPositions),
                               opponentPlayerPositions(opponentPlayerPositions){}

