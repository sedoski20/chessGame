#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <algorithm>
#include "game.h"
#include "player.h"
#include "iplayer.h"
#include "pawn.h"
#include "board.h"
#include "testcases_data.h"

class BoardMock : public IBoard
{
    public:
    BoardMock() {};
    ~BoardMock() {};
    MOCK_METHOD(bool, isPieceSelected, (), (const, override));
    MOCK_METHOD(bool, select, (Position&), (override));
    MOCK_METHOD(bool, moveSelectedPiece, (Position), (override));
    MOCK_METHOD(const Piece *, getSelectedPiece, (), (const, override));
};

class PlayerMock : public IPlayer
{
    public:
    PlayerMock() {};
    ~PlayerMock() {};
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

    BoardMock* const mock = new BoardMock;
    Game game(mock, players);
    Position first_click(5, 5);
    

    EXPECT_CALL(*mock, isPieceSelected())
    .WillOnce(Return(false));

    EXPECT_CALL(*mock, getSelectedPiece())
    .WillOnce(Return(nullptr))
    .WillOnce(Return(nullptr));

    EXPECT_CALL(*mock, select(first_click))
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

    BoardMock* const mock = new BoardMock;
    Game game(mock, players);

    EXPECT_EQ(game.getHighlightedPositions().size(), 0);
    
    Position first_click(1, 0);
    Position second_click(3, 0);
    const Piece *selected_piece = new Pawn(first_click);

    EXPECT_CALL(*mock, isPieceSelected())
    .WillOnce(Return(false))
    .WillOnce(Return(true));

    EXPECT_CALL(*mock, getSelectedPiece())
    .WillOnce(Return(selected_piece))
    .WillOnce(Return(nullptr));

    EXPECT_CALL(*mock, select(first_click))
    .WillOnce(Return(true));

    EXPECT_CALL(*mock, moveSelectedPiece(second_click))
    .WillOnce(Return(true));
    
    //Try to select a first pawn
    EXPECT_EQ(game.getPlayerTurn(), PlayerTurn::TURN_PLAYER1);
    game.selectPosition(first_click);

    EXPECT_EQ(game.getHighlightedPositions().size(), 3);

    //Try to move the first pawn
    game.selectPosition(second_click);

    EXPECT_EQ(game.getHighlightedPositions().size(), 0);
    EXPECT_EQ(game.getPlayerTurn(), PlayerTurn::TURN_PLAYER2);

    delete selected_piece;
}

TEST(GameTestCase, EndingGame)
{
    CheckMate t;

    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_DOWN);
    PlayerTurn turn = PlayerTurn::TURN_PLAYER1;
    PlayerManager * players = new PlayerManager(player1, player2, &turn);

    // Creating a initial state game and checking status
    Board *board = new Board(players);
    Game *game = new Game(board, players);

    EXPECT_EQ(game->getGameStatus(), GameStatus::PLAYING);

    delete game;

    // Changing the state to check mate mocking the players objects
    PlayerMock* const mock1 = new PlayerMock();
    PlayerMock* const mock2 = new PlayerMock();

    EXPECT_CALL(*mock1, getKingPosition()).WillRepeatedly(Return(t.king_position));
    EXPECT_CALL(*mock1, getPieces()).WillRepeatedly(Return(t.current_player));
    EXPECT_CALL(*mock2, getPieces()).WillRepeatedly(Return(t.opponent_player));

    players = new PlayerManager(mock1, mock2, &turn);
    board = new Board(players);
    game = new Game(board, players);

    EXPECT_EQ(game->getGameStatus(), GameStatus::ENDED);

    delete game;
}
