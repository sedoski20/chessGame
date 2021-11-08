#ifndef GAME_H
#define GAME_H

#include "iplayer.h"
#include "iboard.h"
#include "board.h"
#include "igame.h"

enum class PlayerTurn
{
    TURN_PLAYER1,
    TURN_PLAYER2
};

class Game : public IGame
{

private:
    IPlayer *player1;
    IPlayer *player2;
    IPlayer *getCurrentPlayer();
    IPlayer *getOpponentPlayer();

    IBoard *board;
    Board board2;
    PlayerTurn turn;

    void updateTurn();
    void updateBoard();
    void firstClick(Position position);
    void secondClick(Position position);

public:
    Game(IPlayer *player1, IPlayer *player2);
    void selectPosition(Position position);
    void resetGame();
    std::list<PositionStatus> getBoardStatus();
    std::list<PieceInfo> getPlayer1Pieces();
    std::list<PieceInfo> getPlayer2Pieces();
};

#endif // GAME_H
