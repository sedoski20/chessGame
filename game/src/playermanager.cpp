#include "playermanager.h"

PlayerManager::PlayerManager(IPlayer *player1, IPlayer *player2, const PlayerTurn* turn)
                            : player1(player1), player2(player2), turn(turn) {}

IPlayer *PlayerManager::getPlayer1() const 
{ 
    return this->player1; 
}

IPlayer *PlayerManager::getPlayer2() const 
{ 
    return this-> player2; 
}

IPlayer *PlayerManager::getCurrentPlayer() const 
{
    return (*this->turn == PlayerTurn::TURN_PLAYER1) ? this->player1
                                                    : this->player2; 
}

IPlayer *PlayerManager::getOpponentPlayer() const 
{
    return (*this->turn == PlayerTurn::TURN_PLAYER1) ? this->player2
                                                    : this->player1; 
}

