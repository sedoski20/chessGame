#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include "position.h"
#include "iplayer.h"

class IGame
{

public:
    virtual void selectPosition(Position position) = 0;
    virtual void resetGame() = 0;
    virtual bool isPlayer1Turn() = 0;
    virtual std::list<PositionStatus> getBoardStatus() = 0;
    virtual std::list<PieceInfo> getPlayer1Pieces() = 0;
    virtual std::list<PieceInfo> getPlayer2Pieces() = 0;
};

#endif // GAMEINTERFACE_H
