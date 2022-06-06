#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include "position.h"
#include "pieceinfo.h"
#include "positionstatus.h"
#include "playerturn.h"

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
    virtual const std::list<PositionStatus> getHighlightedPositions() const = 0;
    virtual const std::list<PieceInfo> getPlayer1Pieces() const = 0;
    virtual const std::list<PieceInfo> getPlayer2Pieces() const = 0;
    virtual PlayerTurn getPlayerTurn() const = 0;
};

#endif // GAMEINTERFACE_H
