#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include "position.h"

class IGame
{

public:
    virtual void selectPosition(Position position) = 0;
    virtual void resetGame() = 0;
    virtual std::list<PositionStatus> getBoardStatus() = 0;
};

#endif // GAMEINTERFACE_H
