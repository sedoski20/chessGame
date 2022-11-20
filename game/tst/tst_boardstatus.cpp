#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <algorithm>
#include "boardstatus.h"
#include "testcases_data.h"

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

class BoardStatusTestCase : public ::testing::Test
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
            delete players;
            delete boardEngine; 
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

TEST_F(BoardStatusTestCase, kingEscaping)
{
    KingEscaping t;

    EXPECT_CALL(*mock1, getKingPosition()).WillRepeatedly(Return(t.king_position));
    EXPECT_CALL(*mock1, getPieces()).WillRepeatedly(Return(t.current_player));
    EXPECT_CALL(*mock2, getPieces()).WillRepeatedly(Return(t.opponent_player));

    BoardStatus status(players);
    status.update(t.selected_piece);

    std::list<PositionStatus> highlited_positions = status.getHighlightedPositions();

    std::list<PositionStatus> expected_list;
    expected_list.push_back(PositionStatus(Position(0,1), Status::HIGHLIGHTED));
    expected_list.push_back(PositionStatus(Position(1,1), Status::HIGHLIGHTED));
    expected_list.push_back(PositionStatus(Position(0,0), Status::CHECK));

    int equals = countEquals(highlited_positions, expected_list); 
    EXPECT_EQ(highlited_positions.size(), expected_list.size());
    EXPECT_EQ(expected_list.size(), equals);

}

TEST_F(BoardStatusTestCase, kingAttacking)
{
    KingAttacking t;

    EXPECT_CALL(*mock1, getKingPosition()).WillRepeatedly(Return(t.king_position));
    EXPECT_CALL(*mock1, getPieces()).WillRepeatedly(Return(t.current_player));
    EXPECT_CALL(*mock2, getPieces()).WillRepeatedly(Return(t.opponent_player));

    BoardStatus status(players);
    status.update(t.selected_piece);

    std::list<PositionStatus> highlited_positions = status.getHighlightedPositions();

    std::list<PositionStatus> expected_list;
    expected_list.push_back(PositionStatus(Position(1,0), Status::ATTACK));
    expected_list.push_back(PositionStatus(Position(0,0), Status::CHECK));

    int equals = countEquals(highlited_positions, expected_list); 
    EXPECT_EQ(highlited_positions.size(), expected_list.size());
    EXPECT_EQ(expected_list.size(), equals);

}

TEST_F(BoardStatusTestCase, kingProtectionFence)
{
    KingProtectionFence t;

    EXPECT_CALL(*mock1, getKingPosition()).WillRepeatedly(Return(t.king_position));
    EXPECT_CALL(*mock1, getPieces()).WillRepeatedly(Return(t.current_player));
    EXPECT_CALL(*mock2, getPieces()).WillRepeatedly(Return(t.opponent_player));


    BoardStatus status(players);
    status.update(t.selected_piece);

    std::list<PositionStatus> highlited_positions = status.getHighlightedPositions();

    std::list<PositionStatus> expected_list;
    expected_list.push_back(PositionStatus(Position(1,1), Status::SELECTED));
    expected_list.push_back(PositionStatus(Position(2,1), Status::HIGHLIGHTED));
    expected_list.push_back(PositionStatus(Position(1,0), Status::CHECK));

    int equals = countEquals(highlited_positions, expected_list); 
    EXPECT_EQ(highlited_positions.size(), expected_list.size());
    EXPECT_EQ(expected_list.size(), equals);
}

TEST_F(BoardStatusTestCase, kingProtectionAttack)
{
    KingProtectionAttack t;

    EXPECT_CALL(*mock1, getKingPosition()).WillRepeatedly(Return(t.king_position));
    EXPECT_CALL(*mock1, getPieces()).WillRepeatedly(Return(t.current_player));
    EXPECT_CALL(*mock2, getPieces()).WillRepeatedly(Return(t.opponent_player));

    BoardStatus status(players);
    status.update(t.selected_piece);

    std::list<PositionStatus> highlited_positions = status.getHighlightedPositions();

    std::list<PositionStatus> expected_list;
    expected_list.push_back(PositionStatus(Position(1,1), Status::SELECTED));
    expected_list.push_back(PositionStatus(Position(2,1), Status::HIGHLIGHTED));
    expected_list.push_back(PositionStatus(Position(2,2), Status::ATTACK));
    expected_list.push_back(PositionStatus(Position(2,0), Status::CHECK));

    int equals = countEquals(highlited_positions, expected_list); 
    EXPECT_EQ(highlited_positions.size(), expected_list.size());
    EXPECT_EQ(expected_list.size(), equals);
}

TEST_F(BoardStatusTestCase, noSafeMovements1)
{
    NoSafeMovements1 t;

    EXPECT_CALL(*mock1, getKingPosition()).WillRepeatedly(Return(t.king_position));
    EXPECT_CALL(*mock1, getPieces()).WillRepeatedly(Return(t.current_player));
    EXPECT_CALL(*mock2, getPieces()).WillRepeatedly(Return(t.opponent_player));

    BoardStatus status(players);
    status.update(t.selected_piece);

    std::list<PositionStatus> highlited_positions = status.getHighlightedPositions();

    std::list<PositionStatus> expected_list;
    expected_list.push_back(PositionStatus(Position(1,1), Status::SELECTED));

    int equals = countEquals(highlited_positions, expected_list); 
    EXPECT_EQ(highlited_positions.size(), expected_list.size());
    EXPECT_EQ(expected_list.size(), equals);
}