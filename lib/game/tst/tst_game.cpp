#include <gtest/gtest.h>
#include "../src/game.h"
#include "../src/player.h"
#include "../src/iplayer.h"
#include "../src/igame.h"
#include <algorithm>


TEST(GameTestCase, FirstClickOnBlocked)
{

    Player p1(MovementDirection::MOVING_UP, "p1");
    Player p2(MovementDirection::MOVING_DOWN, "p2");

    IPlayer* players[] = {&p1, &p2};
    Game game(players[0], players[1]);

    EXPECT_EQ(game.getBoardStatus().size(), 0);

    //Try to select a blocked piece
    game.selectPosition(Position(0, 0));
    EXPECT_EQ(game.getBoardStatus().size(), 1);
    EXPECT_EQ(p1.isPieceSelected(), true);
    EXPECT_EQ(p2.isPieceSelected(), false);

}
TEST(GameTestCase, FirstClickOnEmpty)
{

    Player p1(MovementDirection::MOVING_UP, "p1");
    Player p2(MovementDirection::MOVING_DOWN, "p2");

    IPlayer* players[] = {&p1, &p2};
    Game game(players[0], players[1]);

    EXPECT_EQ(game.getBoardStatus().size(), 0);

    //Try to select a empty position
    game.selectPosition(Position(5, 5));
    EXPECT_EQ(game.getBoardStatus().size(), 0);
    EXPECT_EQ(p1.isPieceSelected(), false);
    EXPECT_EQ(p2.isPieceSelected(), false);
}
TEST(GameTestCase, MoveTestCase1)
{
    Player p1(MovementDirection::MOVING_UP, "p1");
    Player p2(MovementDirection::MOVING_DOWN, "p2");

    IPlayer* players[] = {&p1, &p2};
    Game game(players[0], players[1]);

    EXPECT_EQ(game.getBoardStatus().size(), 0);

    //Try to select a first pawn
    game.selectPosition(Position(1, 0));
    EXPECT_EQ(game.getBoardStatus().size(), 3);
    EXPECT_EQ(p1.isPieceSelected(), true);
    EXPECT_EQ(p2.isPieceSelected(), false);

    //Try to move the first pawn
    game.selectPosition(Position(3, 0));
    EXPECT_EQ(game.getBoardStatus().size(), 0);
    EXPECT_EQ(p1.isPieceSelected(), false);
    EXPECT_EQ(p2.isPieceSelected(), false);
}
