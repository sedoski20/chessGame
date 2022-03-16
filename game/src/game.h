#ifndef GAME_H
#define GAME_H

#include "iboard.h"
#include "igame.h"

class Game : public IGame
{

private:

    IBoard *board;
    PlayerTurn turn;
    GameStatus status;
    BoardStatus boardStatus;

    void updateBoard();
    void firstClick(Position position);
    void secondClick(Position position);

public:
    Game();
    void selectPosition(Position position);
    const BoardStatus getBoardStatus() const { return this->boardStatus; };
    const GameStatus getGameStatus() const { return status; }
};

#endif // GAME_H
