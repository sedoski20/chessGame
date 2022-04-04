#include <gtest/gtest.h>
#include <algorithm>
#include "boardstatus.h"
#include "boardengine_testcases_data.h"

class PlayerFake : public Player
{   
    public:
    PlayerFake(MovementDirection direction) : Player(direction){}; 
    
    void setPieces(std::list<const Piece *> pieces)
    {
        this->pieces.clear();

        for(const Piece * piece : pieces)
            this->pieces.push_back(const_cast<Piece *>(piece));

    }
};

class BoardStatusTestCase : public ::testing::Test
{
    protected:
        void SetUp() override
        {
            mock1 = new PlayerFake(MovementDirection::MOVING_UP);
            mock2 = new PlayerFake(MovementDirection::MOVING_DOWN); 
            IPlayer * player1 = mock1;  
            IPlayer * player2 = mock2;
            turn = PlayerTurn::TURN_PLAYER1;

            players = new PlayerManager(player1, player2, &turn);
            boardEngine = new BoardEngine(players);
        }

        void TearDown() override 
        { 
            delete players;
            delete boardEngine; 
            delete mock1;
            delete mock2;
        }

        PlayerFake *mock1;
        PlayerFake *mock2;
        BoardEngine *boardEngine;
        PlayerManager *players;
        PlayerTurn turn;
};

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
    using namespace kingEscaping;

    mock1->setPieces(current_player);
    mock2->setPieces(opponent_player);

    BoardStatus status(players);
    status.update(selected_piece);

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
    using namespace kingAttacking;

    mock1->setPieces(current_player);
    mock2->setPieces(opponent_player);

    BoardStatus status(players);
    status.update(selected_piece);

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
    using namespace kingProtectionFence;

    mock1->setPieces(current_player);
    mock2->setPieces(opponent_player);

    BoardStatus status(players);
    status.update(selected_piece);

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
    using namespace kingProtectionAttack;

    mock1->setPieces(current_player);
    mock2->setPieces(opponent_player);

    BoardStatus status(players);
    status.update(selected_piece);

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
    using namespace noSafeMovements1;

    mock1->setPieces(current_player);
    mock2->setPieces(opponent_player);

    BoardStatus status(players);
    status.update(selected_piece);

    std::list<PositionStatus> highlited_positions = status.getHighlightedPositions();

    std::list<PositionStatus> expected_list;
    expected_list.push_back(PositionStatus(Position(1,1), Status::SELECTED));

    int equals = countEquals(highlited_positions, expected_list); 
    EXPECT_EQ(highlited_positions.size(), expected_list.size());
    EXPECT_EQ(expected_list.size(), equals);
}