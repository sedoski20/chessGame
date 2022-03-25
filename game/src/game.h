#ifndef GAME_H
#define GAME_H

#include "iboard.h"
#include "igame.h"

class Game : public IGame
{

private:

    IBoard *board;
    GameStatus status;

    void updateBoard();
    void firstClick(Position position);
    void secondClick(Position position);

public:
    Game();
    void selectPosition(Position position);
    const BoardStatus getBoardStatus() const { return this->board->getBoardStatus(); };
    const GameStatus getGameStatus() const { return status; }
};

#endif // GAME_H
