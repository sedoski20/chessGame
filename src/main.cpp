#include <iostream>
#include "game.h"
#include "iplayer.h"
#include "player.h"
#include "IBoard.h"
#include "Board.h"

int main()
{

    Player player1(MovementDirection::MOVING_UP);
    Player player2(MovementDirection::MOVING_DOWN);
    IPlayer *iplayer1 = &player1;
    IPlayer *iplayer2 = &player2;

    Game game(iplayer1, iplayer2);
    game.selectPosition(Position(0,0));

    return 0;

}