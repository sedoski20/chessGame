#ifndef GAME_H
#define GAME_H

#include "iplayer.h"
#include "iboard.h"
#include "board.h"
#include "position.h"

enum class PlayerTurn
{
    TURN_PLAYER1,
    TURN_PLAYER2
};

class Game
{

private:
    IPlayer *player1;
    IPlayer *player2;
    IPlayer *getCurrentPlayer();
    IPlayer *getOpponentPlayer();

    IBoard *board;
    PlayerTurn turn;

    void updateTurn();
    void updateBoard();
    void firstClick(Position position);
    void secondClick(Position position);

public:
    Game(IPlayer *player1, IPlayer *player2);
    void selectPosition(Position position);
    void resetGame();
};

#endif // GAME_H
