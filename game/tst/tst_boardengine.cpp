#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <algorithm>
#include "boardengine.h"
#include "testcases_data.h"
#include "player.h"

class PlayerMock : public IPlayer
{
    public:
    PlayerMock() {};
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
            turn = PlayerTurn::TURN_PLAYER1;
            mock1 = new PlayerMock();
            mock2 = new PlayerMock();
            players = new PlayerManager(mock1, mock2, &turn);
            boardEngine = new BoardEngine(players);
        }

        void TearDown() override 
        { 
            delete boardEngine;
            delete players;
            deleteMocks();
        }

        void deleteMocks()
        {
            delete mock1;
            delete mock2;
        }

        PlayerMock *mock1; 
        PlayerMock *mock2;
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
    KingEscaping t;

    EXPECT_CALL(*mock1, getKingPosition()).WillRepeatedly(Return(t.king_position));
    EXPECT_CALL(*mock1, getPieces()).WillRepeatedly(Return(t.current_player));
    EXPECT_CALL(*mock2, getPieces()).WillRepeatedly(Return(t.opponent_player));
    std::list<Position> possible_movements = boardEngine->getPossibleMovements(t.selected_piece);

    int equals = countEquals(possible_movements, t.possible_movements_expected);
    EXPECT_EQ(t.possible_movements_expected.size(), equals);
    EXPECT_EQ(t.possible_movements_expected.size(), possible_movements.size());

    bool is_check_mate = boardEngine->isCheckMate();
    bool is_check = boardEngine->isCheck();
    EXPECT_EQ(is_check, true);
    EXPECT_EQ(is_check_mate, false);
} 

TEST_F(BoardEngineTestCase, kingAttacking)
{
    KingAttacking t;

    EXPECT_CALL(*mock1, getKingPosition()).WillRepeatedly(Return(t.king_position));
    EXPECT_CALL(*mock1, getPieces()).WillRepeatedly(Return(t.current_player));
    EXPECT_CALL(*mock2, getPieces()).WillRepeatedly(Return(t.opponent_player));
    std::list<Position> possible_movements = boardEngine->getPossibleMovements(t.selected_piece);

    int equals = countEquals(possible_movements, t.possible_movements_expected);
    EXPECT_EQ(t.possible_movements_expected.size(), equals);
    EXPECT_EQ(t.possible_movements_expected.size(), possible_movements.size());

    bool is_check_mate = boardEngine->isCheckMate();
    bool is_check = boardEngine->isCheck();
    EXPECT_EQ(is_check, true);
    EXPECT_EQ(is_check_mate, false);
} 

TEST_F(BoardEngineTestCase, kingProtectionFence)
{
    KingProtectionFence t;

    EXPECT_CALL(*mock1, getKingPosition()).WillRepeatedly(Return(t.king_position));
    EXPECT_CALL(*mock1, getPieces()).WillRepeatedly(Return(t.current_player));
    EXPECT_CALL(*mock2, getPieces()).WillRepeatedly(Return(t.opponent_player));
    std::list<Position> possible_movements = boardEngine->getPossibleMovements(t.selected_piece);

    int equals = countEquals(possible_movements, t.possible_movements_expected);
    EXPECT_EQ(t.possible_movements_expected.size(), equals);
    EXPECT_EQ(t.possible_movements_expected.size(), possible_movements.size());

    bool is_check_mate = boardEngine->isCheckMate();
    bool is_check = boardEngine->isCheck();
    EXPECT_EQ(is_check, true);
    EXPECT_EQ(is_check_mate, false);
} 

TEST_F(BoardEngineTestCase, kingProtectionAttack)
{
    KingProtectionAttack t;

    EXPECT_CALL(*mock1, getKingPosition()).WillRepeatedly(Return(t.king_position));
    EXPECT_CALL(*mock1, getPieces()).WillRepeatedly(Return(t.current_player));
    EXPECT_CALL(*mock2, getPieces()).WillRepeatedly(Return(t.opponent_player));
    std::list<Position> possible_movements = boardEngine->getPossibleMovements(t.selected_piece);

    int equals = countEquals(possible_movements, t.possible_movements_expected);
    EXPECT_EQ(t.possible_movements_expected.size(), equals);
    EXPECT_EQ(t.possible_movements_expected.size(), possible_movements.size());
    
    bool is_check_mate = boardEngine->isCheckMate();
    bool is_check = boardEngine->isCheck();
    EXPECT_EQ(is_check, true);
    EXPECT_EQ(is_check_mate, false);
} 

TEST_F(BoardEngineTestCase, noSafeMovements1)
{
    NoSafeMovements1 t;

    EXPECT_CALL(*mock1, getKingPosition()).WillRepeatedly(Return(t.king_position));
    EXPECT_CALL(*mock1, getPieces()).WillRepeatedly(Return(t.current_player));
    EXPECT_CALL(*mock2, getPieces()).WillRepeatedly(Return(t.opponent_player));
    std::list<Position> possible_movements = boardEngine->getPossibleMovements(t.selected_piece);

    int equals = countEquals(possible_movements, t.possible_movements_expected);
    EXPECT_EQ(t.possible_movements_expected.size(), equals);
    EXPECT_EQ(t.possible_movements_expected.size(), possible_movements.size());

    bool is_check_mate = boardEngine->isCheckMate();
    bool is_check = boardEngine->isCheck();
    EXPECT_EQ(is_check, false);
    EXPECT_EQ(is_check_mate, false);
    
} 

TEST_F(BoardEngineTestCase, noSafeMovements2)
{
    NoSafeMovements2 t;

    EXPECT_CALL(*mock1, getKingPosition()).WillRepeatedly(Return(t.king_position));
    EXPECT_CALL(*mock1, getPieces()).WillRepeatedly(Return(t.current_player));
    EXPECT_CALL(*mock2, getPieces()).WillRepeatedly(Return(t.opponent_player));
    std::list<Position> possible_movements = boardEngine->getPossibleMovements(t.selected_piece);

    int equals = countEquals(possible_movements, t.possible_movements_expected);
    EXPECT_EQ(t.possible_movements_expected.size(), equals);
    EXPECT_EQ(t.possible_movements_expected.size(), possible_movements.size());

    bool is_check_mate = boardEngine->isCheckMate();
    bool is_check = boardEngine->isCheck();
    EXPECT_EQ(is_check, true);
    EXPECT_EQ(is_check_mate, false);
} 

TEST(BoardEngineTestCase_, isCheck)
{
    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_DOWN); 
    PlayerTurn turn = PlayerTurn::TURN_PLAYER1;

    PlayerManager *players_ = new PlayerManager(player1, player2, &turn);
    BoardEngine *board_engine = new BoardEngine(players_);

    bool is_check_mate = board_engine->isCheckMate();
    bool is_check = board_engine->isCheck();
    EXPECT_EQ(is_check, false);
    EXPECT_EQ(is_check_mate, false);

    delete player1;
    delete player2;
    delete players_;
    delete board_engine;
} 

TEST_F(BoardEngineTestCase, checkMate)
{
    CheckMate t;

    EXPECT_CALL(*mock1, getKingPosition()).WillRepeatedly(Return(t.king_position));
    EXPECT_CALL(*mock1, getPieces()).WillRepeatedly(Return(t.current_player));
    EXPECT_CALL(*mock2, getPieces()).WillRepeatedly(Return(t.opponent_player));
    std::list<Position> possible_movements = boardEngine->getPossibleMovements(t.selected_piece);

    EXPECT_EQ(possible_movements.size(), 0);

    bool is_check_mate = boardEngine->isCheckMate();
    bool is_check = boardEngine->isCheck();
    EXPECT_EQ(is_check, true);
    EXPECT_EQ(is_check_mate, true);
} 

TEST_F(BoardEngineTestCase, isAttack1)
{
    KingProtectionAttack t;

    EXPECT_CALL(*mock1, getPieces()).WillRepeatedly(Return(t.current_player));
    EXPECT_CALL(*mock2, getPieces()).WillRepeatedly(Return(t.opponent_player));

    bool is_attack = boardEngine->isAttack(Position(2,2));
    EXPECT_EQ(is_attack, true);
} 

TEST_F(BoardEngineTestCase, isAttack2)
{
    KingEscaping t;

    EXPECT_CALL(*mock1, getPieces()).WillRepeatedly(Return(t.current_player));
    EXPECT_CALL(*mock2, getPieces()).WillRepeatedly(Return(t.opponent_player));

    bool is_attack = boardEngine->isAttack(Position(1,1));
    EXPECT_EQ(is_attack, false);
} 