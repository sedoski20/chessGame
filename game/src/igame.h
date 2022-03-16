#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include "position.h"
#include "boardstatus.h"

enum class GameStatus
{
    INITIAL,
    PLAYING,
    ENDED,
};

class IGame
{

public:
    virtual void selectPosition(Position position) = 0;
    virtual const GameStatus getGameStatus() const = 0;
    virtual const BoardStatus getBoardStatus() const = 0;
};

#endif // GAMEINTERFACE_H
