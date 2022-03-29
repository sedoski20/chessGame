#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "iplayer.h"

enum class PlayerTurn
{
    TURN_PLAYER1,
    TURN_PLAYER2
};

class PlayerManager
{
private:
    IPlayer *player1;
    IPlayer *player2;
    PlayerTurn turn;

public:
    PlayerManager(IPlayer *player1, IPlayer *player2);
    IPlayer *getPlayer1() const;
    IPlayer *getPlayer2() const;
    IPlayer *getCurrentPlayer() const;
    IPlayer *getOpponentPlayer() const;
    void updateTurn();
};

#endif // PLAYERMANAGER_H
