#ifndef GAME_H
#define GAME_H

#include "iboard.h"
#include "igame.h"
#include "playerturn.h"

class Game : public IGame
{

private:

    IBoard *board;
    PlayerManager *players;
    PlayerTurn turn;

    void updateTurn();
    bool firstClick(Position position) const;
    bool secondClick(Position position) const;

public:
    Game();
    Game(IBoard *board, PlayerManager * players);
    ~Game();
    void selectPosition(Position position);
    const BoardStatus getBoardStatus() const;
    const GameStatus getGameStatus() const;
    PlayerTurn getPlayerTurn() const {return this->turn; };
};

#endif // GAME_H
