#ifndef BOARDSTATUS_H
#define BOARDSTATUS_H

#include "positionstatus.h"
#include "boardpositions.h"
#include <list>

class BoardStatus
{
private:
    std::list<PositionStatus> boardStatus;

public:
    BoardStatus();
    void resetStatus();
    void addPossibleMovements(std::list<Position> &possibleMovements, const BoardPositions &board);
    void addSelectedPiece(Position selectedPiece); 
    void addCheck(Position kingPosition);
    Status getStatus(Position position) const;
};


#endif // BOARDSTATUS_H
