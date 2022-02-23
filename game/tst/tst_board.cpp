#include "gtest/gtest.h"
#include "../src/board.h"
#include <algorithm>

TEST(BoardTestCase, ConstructorTestCase1)
{
    IPlayer *player1;
    IPlayer *player2;
    Board board(player1, player2);
    EXPECT_EQ(board.getBoardStatus().size(), 0);
    EXPECT_EQ(board.getPlayer1Pieces().size(), 0);
    EXPECT_EQ(board.getPlayer2Pieces().size(), 0);
}

TEST(BoardTestCase, updateBoard)
{
    IPlayer *player1;
    IPlayer *player2;
    Board board(player1, player2);

    std::list<Position> positions;
    std::list<Position> opponent_positions;

    positions.push_back(Position(1, 1));
    positions.push_back(Position(2, 2));
    positions.push_back(Position(3, 3));
    positions.push_back(Position(4, 4));

    board.updateBoardStatus();
    EXPECT_EQ(board.getBoardStatus().size(), positions.size());

    std::list<PositionStatus> status = board.getBoardStatus();
	std::list<Position>::iterator iterator;

    for(auto &position : status)
    {
        iterator = std::find(positions.begin(), positions.end(), position.position);
        bool found_m1 = (iterator != std::end(positions));
        EXPECT_EQ(found_m1, true);
    }
}

TEST(BoardTestCase, resetBoardStatus)
{
    IPlayer *player1;
    IPlayer *player2;
    Board board(player1, player2);

    std::list<Position> positions;
    std::list<Position> opponent_positions;

    positions.push_back(Position(1, 1));
    positions.push_back(Position(2, 2));
    positions.push_back(Position(3, 3));
    positions.push_back(Position(4, 4));

    board.updateBoardStatus();
    EXPECT_EQ(board.getBoardStatus().size(), positions.size());

    std::list<PositionStatus> status = board.getBoardStatus();
	std::list<Position>::iterator iterator;

    for(auto &position : status)
    {
        iterator = std::find(positions.begin(), positions.end(), position.position);
        bool found_m1 = (iterator != std::end(positions));
        EXPECT_EQ(found_m1, true);
    }

    board.resetBoardStatus();
    EXPECT_EQ(board.getBoardStatus().size(), 0);
}


