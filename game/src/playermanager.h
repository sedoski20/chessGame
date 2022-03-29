#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "iplayer.h"
#include "playerturn.h"

class PlayerManager
{
private:
    IPlayer *player1;
    IPlayer *player2;
    const PlayerTurn *turn;

public:
    PlayerManager(IPlayer *player1, IPlayer *player2, const PlayerTurn* turn);
    IPlayer *getPlayer1() const;
    IPlayer *getPlayer2() const;
    IPlayer *getCurrentPlayer() const;
    IPlayer *getOpponentPlayer() const;
};

#endif // PLAYERMANAGER_H
