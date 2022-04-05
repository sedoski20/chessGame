#include <gtest/gtest.h>
#include "board.h"
#include <algorithm>
#include "player.h"

TEST(BoardTestCase, ConstructorTestCase1)
{
    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_DOWN);
    PlayerTurn turn = PlayerTurn::TURN_PLAYER1;
    PlayerManager players(player1, player2, &turn); 
    Board board(&players);

    EXPECT_EQ(board.isPieceSelected(), true);
}

TEST(BoardTestCase, selectingPiece)
{
    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_DOWN);
    PlayerTurn turn = PlayerTurn::TURN_PLAYER1;
    PlayerManager players(player1, player2, &turn); 
    Board board(&players);

    Position position = Position(1, 0);

    EXPECT_EQ(board.isPieceSelected(), false);
    EXPECT_EQ(board.select(position), true);
    EXPECT_EQ(board.isPieceSelected(), true);
}

TEST(BoardTestCase, selectingEmptyPosition)
{
    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_DOWN);
    PlayerTurn turn = PlayerTurn::TURN_PLAYER1;
    PlayerManager players(player1, player2, &turn); 
    Board board(&players);

    Position position = Position(4, 4);

    EXPECT_EQ(board.isPieceSelected(), false);
    EXPECT_EQ(board.select(position), false);
    EXPECT_EQ(board.isPieceSelected(), false);
}

TEST(BoardTestCase, selectingTwice)
{
    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_DOWN);
    PlayerTurn turn = PlayerTurn::TURN_PLAYER1;
    PlayerManager players(player1, player2, &turn); 
    Board board(&players);

    Position position = Position(0, 1);

    EXPECT_EQ(board.isPieceSelected(), false);
    EXPECT_EQ(board.select(position), true);
    EXPECT_EQ(board.isPieceSelected(), true);
    EXPECT_EQ(board.select(position), true);
    EXPECT_EQ(board.isPieceSelected(), true);
}

TEST(BoardTestCase, getSelectedPiece)
{
    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_DOWN);
    PlayerTurn turn = PlayerTurn::TURN_PLAYER1;
    PlayerManager players(player1, player2, &turn); 
    Board board(&players);

    EXPECT_EQ(board.isPieceSelected(), false);
    EXPECT_EQ(board.getSelectedPiece(), nullptr);
    
    Position position = Position(1, 0);
    
    EXPECT_EQ(board.select(position), true);
    EXPECT_NE(board.getSelectedPiece(), nullptr);
    EXPECT_EQ(board.isPieceSelected(), true);
}

TEST(BoardTestCase, moveSelectedPiece)
{
    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_DOWN);
    PlayerTurn turn = PlayerTurn::TURN_PLAYER1;
    PlayerManager players(player1, player2, &turn); 
    Board board(&players);

    EXPECT_EQ(board.isPieceSelected(), false);    
    
    Position position = Position(1, 0);
    EXPECT_EQ(board.select(position), true);

    EXPECT_EQ(board.moveSelectedPiece(Position(2, 0)), true);
    EXPECT_EQ(board.isPieceSelected(), false);
}

TEST(BoardTestCase, failMovingSelectedPiece)
{
    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_DOWN);
    PlayerTurn turn = PlayerTurn::TURN_PLAYER1;
    PlayerManager players(player1, player2, &turn); 
    Board board(&players);

    EXPECT_EQ(board.isPieceSelected(), false);    
    
    Position position = Position(1, 0);
    EXPECT_EQ(board.select(position), true);

    EXPECT_EQ(board.moveSelectedPiece(Position(3, 1)), false);
    EXPECT_EQ(board.isPieceSelected(), false);
}
