#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <algorithm>
#include "game.h"
#include "player.h"
#include "iplayer.h"
#include "pawn.h"
#include "board.h"
#include "boardengine_testcases_data.h"

class BoardMock : public IBoard
{
    public:
    MOCK_METHOD(bool, isPieceSelected, (), (const, override));
    MOCK_METHOD(bool, select, (Position&), (override));
    MOCK_METHOD(bool, moveSelectedPiece, (Position), (override));
    MOCK_METHOD(const Piece *, getSelectedPiece, (), (const, override));
};

class PlayerMock : public IPlayer
{
    public:
    MOCK_METHOD(Piece*, findPiece, (Position), (const));
    MOCK_METHOD(const std::list<const Piece *>, getPieces, (), (const));
    MOCK_METHOD(bool, capturePiece, (Position));
    MOCK_METHOD(bool, movePiece, (Position, Position));
    MOCK_METHOD(Position, getKingPosition, (), (const));
};

using ::testing::Return;
using ::testing::AtLeast;

TEST(GameTestCase, Starting)
{
    Game game;

    EXPECT_EQ(game.getGameStatus(), GameStatus::PLAYING);
    EXPECT_EQ(game.getHighlightedPositions().size(), 0);
    EXPECT_EQ(game.getPlayerTurn(), PlayerTurn::TURN_PLAYER1);
}

TEST(GameTestCase, FirstClickOnEmpty)
{
    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_DOWN);

    PlayerTurn turn = PlayerTurn::TURN_PLAYER1;
    PlayerManager * players = new PlayerManager(player1, player2, &turn);

    BoardMock mock;
    IBoard* board = &mock;
    Game game(board, players);
    Position first_click(5, 5);
    

    EXPECT_CALL(mock, isPieceSelected())
    .WillOnce(Return(false));

    EXPECT_CALL(mock, getSelectedPiece())
    .WillOnce(Return(nullptr))
    .WillOnce(Return(nullptr));

    EXPECT_CALL(mock, select(first_click))
    .WillOnce(Return(false));

    EXPECT_EQ(game.getHighlightedPositions().size(), 0);

    //Try to select a empty position
    game.selectPosition(Position(5, 5));

    EXPECT_EQ(game.getHighlightedPositions().size(), 0);
    EXPECT_EQ(game.getPlayerTurn(), PlayerTurn::TURN_PLAYER1);
}

TEST(GameTestCase, MoveTestCase1)
{
    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_DOWN);

    PlayerTurn turn = PlayerTurn::TURN_PLAYER1;
    PlayerManager * players = new PlayerManager(player1, player2, &turn);

    BoardMock mock;
    IBoard* board = &mock;
    Game game(board, players);

    EXPECT_EQ(game.getHighlightedPositions().size(), 0);
    
    Position first_click(1, 0);
    Position second_click(3, 0);
    const Piece *selected_piece = new Pawn(first_click);

    EXPECT_CALL(mock, isPieceSelected())
    .WillOnce(Return(false))
    .WillOnce(Return(true));

    EXPECT_CALL(mock, getSelectedPiece())
    .WillOnce(Return(selected_piece))
    .WillOnce(Return(nullptr));

    EXPECT_CALL(mock, select(first_click))
    .WillOnce(Return(true));

    EXPECT_CALL(mock, moveSelectedPiece(second_click))
    .WillOnce(Return(true));
    
    //Try to select a first pawn
    EXPECT_EQ(game.getPlayerTurn(), PlayerTurn::TURN_PLAYER1);
    game.selectPosition(first_click);

    EXPECT_EQ(game.getHighlightedPositions().size(), 3);

    //Try to move the first pawn
    game.selectPosition(second_click);

    EXPECT_EQ(game.getHighlightedPositions().size(), 0);
    EXPECT_EQ(game.getPlayerTurn(), PlayerTurn::TURN_PLAYER2);
}

TEST(GameTestCase, EndingGame)
{
    using namespace checkMate;

    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_DOWN);
    PlayerTurn turn = PlayerTurn::TURN_PLAYER1;
    PlayerManager * players = new PlayerManager(player1, player2, &turn);

    // Creating a initial state game and checking status
    Board board = Board(players);
    IBoard* iboard = &board;
    
    Game game(iboard, players);

    EXPECT_EQ(game.getGameStatus(), GameStatus::PLAYING);

    // Changing the state to check mate mocking the players objects

    PlayerMock mock1;
    PlayerMock mock2;

    EXPECT_CALL(mock1, getPieces()).WillRepeatedly(Return(current_player));
    EXPECT_CALL(mock2, getPieces()).WillRepeatedly(Return(opponent_player));

    player1 = &mock1;
    player2 = &mock2;

    players = new PlayerManager(player1, player2, &turn);
    board = Board(players);
    iboard = &board;
    game = Game(iboard, players);

    EXPECT_EQ(game.getGameStatus(), GameStatus::ENDED);
}
