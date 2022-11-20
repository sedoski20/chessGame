#include <gtest/gtest.h>
#include "playermanager.h"
#include "player.h"

TEST(PlayerManagerTestCase, ConstructorTest)
{
    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_UP);
    PlayerTurn turn = PlayerTurn::TURN_PLAYER1;

    PlayerManager players(player1, player2, &turn);

    EXPECT_EQ(players.getCurrentPlayer(), player1);
    EXPECT_EQ(players.getOpponentPlayer(), player2);
    EXPECT_EQ(players.getPlayer1(), player1);
    EXPECT_EQ(players.getPlayer2(), player2);

    delete player1;
    delete player2;
}

TEST(PlayerManagerTestCase, UpdatingTurn)
{
    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_UP);
    PlayerTurn turn = PlayerTurn::TURN_PLAYER1;

    PlayerManager players(player1, player2, &turn);

    EXPECT_EQ(players.getCurrentPlayer(), player1);
    EXPECT_EQ(players.getOpponentPlayer(), player2);
    EXPECT_EQ(players.getPlayer1(), player1);
    EXPECT_EQ(players.getPlayer2(), player2);

    turn = PlayerTurn::TURN_PLAYER2;

    EXPECT_EQ(players.getCurrentPlayer(), player2);
    EXPECT_EQ(players.getOpponentPlayer(), player1);
    EXPECT_EQ(players.getPlayer1(), player1);
    EXPECT_EQ(players.getPlayer2(), player2);

    delete player1;
    delete player2;
}