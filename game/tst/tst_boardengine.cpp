#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <algorithm>
#include "boardengine.h"
#include "boardengine_testcases_data.h"
#include "player.h"

class PlayerMock : public IPlayer
{
    public:
    MOCK_METHOD(Piece*, findPiece, (Position), (const));
    MOCK_METHOD(const std::list<const Piece *>, getPieces, (), (const));
    MOCK_METHOD(bool, capturePiece, (Position));
    MOCK_METHOD(bool, movePiece, (Position, Position));
    MOCK_METHOD(Position, getKingPosition, (), (const));
};

class BoardEngineTestCase : public ::testing::Test
{
    protected:
        void SetUp() override
        {
            IPlayer *player1 = &mock1;
            IPlayer *player2 = &mock2; 
            turn = PlayerTurn::TURN_PLAYER1;

            players = new PlayerManager(player1, player2, &turn);
            boardEngine = new BoardEngine(players);
        }

        void TearDown() override 
        { 
            delete players;
            delete boardEngine; 
        }

        PlayerMock mock1, mock2;
        BoardEngine *boardEngine;
        PlayerManager *players;
        PlayerTurn turn;
};

using ::testing::Return;

template<typename T>
int countEquals(std::list<T> a, std::list<T> b)
{
    int count = 0;

    for(auto item : a)
    {
        if(std::find(b.begin(), b.end(), item) != b.end())
            count++;
    }

    return count;
}

TEST_F(BoardEngineTestCase, kingEscaping)
{
    using namespace kingEscaping;

    EXPECT_CALL(mock1, getKingPosition()).WillRepeatedly(Return(king_position));
    EXPECT_CALL(mock1, getPieces()).WillRepeatedly(Return(current_player));
    EXPECT_CALL(mock2, getPieces()).WillRepeatedly(Return(opponent_player));
    std::list<Position> possible_movements = boardEngine->getPossibleMovements(selected_piece);

    int equals = countEquals(possible_movements, possible_movements_expected);
    EXPECT_EQ(possible_movements.size(), equals);

    bool is_check_mate = boardEngine->isCheckmate();
    bool is_check = boardEngine->isCheckArrangement(boardEngine->getBoardPositions(), king_position);
    EXPECT_EQ(is_check, true);
    EXPECT_EQ(is_check_mate, false);
} 

TEST_F(BoardEngineTestCase, kingAttacking)
{
    using namespace kingAttacking;

    EXPECT_CALL(mock1, getKingPosition()).WillRepeatedly(Return(king_position));
    EXPECT_CALL(mock1, getPieces()).WillRepeatedly(Return(current_player));
    EXPECT_CALL(mock2, getPieces()).WillRepeatedly(Return(opponent_player));
    std::list<Position> possible_movements = boardEngine->getPossibleMovements(selected_piece);

    int equals = countEquals(possible_movements, possible_movements_expected);
    EXPECT_EQ(possible_movements.size(), equals);

    bool is_check_mate = boardEngine->isCheckmate();
    bool is_check = boardEngine->isCheckArrangement(boardEngine->getBoardPositions(), king_position);
    EXPECT_EQ(is_check, true);
    EXPECT_EQ(is_check_mate, false);
} 

TEST_F(BoardEngineTestCase, kingProtectionFence)
{
    using namespace kingProtectionFence;

    EXPECT_CALL(mock1, getKingPosition()).WillRepeatedly(Return(king_position));
    EXPECT_CALL(mock1, getPieces()).WillRepeatedly(Return(current_player));
    EXPECT_CALL(mock2, getPieces()).WillRepeatedly(Return(opponent_player));
    std::list<Position> possible_movements = boardEngine->getPossibleMovements(selected_piece);

    int equals = countEquals(possible_movements, possible_movements_expected);
    EXPECT_EQ(possible_movements.size(), equals);

    bool is_check_mate = boardEngine->isCheckmate();
    bool is_check = boardEngine->isCheckArrangement(boardEngine->getBoardPositions(), king_position);
    EXPECT_EQ(is_check, true);
    EXPECT_EQ(is_check_mate, false);
} 

TEST_F(BoardEngineTestCase, kingProtectionAttack)
{
    using namespace kingProtectionAttack;

    EXPECT_CALL(mock1, getKingPosition()).WillRepeatedly(Return(king_position));
    EXPECT_CALL(mock1, getPieces()).WillRepeatedly(Return(current_player));
    EXPECT_CALL(mock2, getPieces()).WillRepeatedly(Return(opponent_player));
    std::list<Position> possible_movements = boardEngine->getPossibleMovements(selected_piece);

    int equals = countEquals(possible_movements, possible_movements_expected);
    EXPECT_EQ(possible_movements.size(), equals);
    
    bool is_check_mate = boardEngine->isCheckmate();
    bool is_check = boardEngine->isCheckArrangement(boardEngine->getBoardPositions(), king_position);
    EXPECT_EQ(is_check, true);
    EXPECT_EQ(is_check_mate, false);
} 

TEST_F(BoardEngineTestCase, noSafeMovements1)
{
    using namespace noSafeMovements1;

    EXPECT_CALL(mock1, getKingPosition()).WillRepeatedly(Return(king_position));
    EXPECT_CALL(mock1, getPieces()).WillRepeatedly(Return(current_player));
    EXPECT_CALL(mock2, getPieces()).WillRepeatedly(Return(opponent_player));
    std::list<Position> possible_movements = boardEngine->getPossibleMovements(selected_piece);

    int equals = countEquals(possible_movements, possible_movements_expected);
    EXPECT_EQ(possible_movements.size(), equals);

    bool is_check_mate = boardEngine->isCheckmate();
    bool is_check = boardEngine->isCheckArrangement(boardEngine->getBoardPositions(), king_position);
    EXPECT_EQ(is_check, false);
    EXPECT_EQ(is_check_mate, false);
    
} 

TEST_F(BoardEngineTestCase, noSafeMovements2)
{
    using namespace noSafeMovements2;

    EXPECT_CALL(mock1, getKingPosition()).WillRepeatedly(Return(king_position));
    EXPECT_CALL(mock1, getPieces()).WillRepeatedly(Return(current_player));
    EXPECT_CALL(mock2, getPieces()).WillRepeatedly(Return(opponent_player));
    std::list<Position> possible_movements = boardEngine->getPossibleMovements(selected_piece);

    int equals = countEquals(possible_movements, possible_movements_expected);
    EXPECT_EQ(possible_movements.size(), equals);

    bool is_check_mate = boardEngine->isCheckmate();
    bool is_check = boardEngine->isCheckArrangement(boardEngine->getBoardPositions(), king_position);
    EXPECT_EQ(is_check, true);
    EXPECT_EQ(is_check_mate, false);
} 

TEST_F(BoardEngineTestCase, isCheck)
{
    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_DOWN); 
    PlayerTurn turn = PlayerTurn::TURN_PLAYER1;

    PlayerManager *players = new PlayerManager(player1, player2, &turn);
    boardEngine = new BoardEngine(players);

    bool is_check_mate = boardEngine->isCheckmate();
    bool is_check = boardEngine->isCheckArrangement(boardEngine->getBoardPositions(), player1->getKingPosition());
    EXPECT_EQ(is_check, false);
    EXPECT_EQ(is_check_mate, false);
} 

TEST_F(BoardEngineTestCase, checkMate)
{
    using namespace checkMate;

    EXPECT_CALL(mock1, getKingPosition()).WillRepeatedly(Return(king_position));
    EXPECT_CALL(mock1, getPieces()).WillRepeatedly(Return(current_player));
    EXPECT_CALL(mock2, getPieces()).WillRepeatedly(Return(opponent_player));
    std::list<Position> possible_movements = boardEngine->getPossibleMovements(selected_piece);

    EXPECT_EQ(possible_movements.size(), 0);

    bool is_check_mate = boardEngine->isCheckmate();
    bool is_check = boardEngine->isCheckArrangement(boardEngine->getBoardPositions(), king_position);
    EXPECT_EQ(is_check, true);
    EXPECT_EQ(is_check_mate, true);
} 