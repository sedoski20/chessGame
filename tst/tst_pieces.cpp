#include <gtest/gtest.h>
#include <algorithm>
#include "../src/pawn.h"

TEST(PawnTestCase, ConstructorTest1)
{
	Position initial_position(0, 0);
	Pawn pawn(initial_position);
	
	EXPECT_EQ(pawn.getCurrentPosition().row, 0);
	EXPECT_EQ(pawn.getCurrentPosition().column, 0);
}
TEST(PawnTestCase, ConstructorTest2)
{
	Position initial_position(4, 5);
	Pawn pawn(initial_position); 	

	EXPECT_EQ(pawn.getCurrentPosition().row, 4);
	EXPECT_EQ(pawn.getCurrentPosition().column, 5);
}
TEST(PawnTestCase, ConstructorTest3)
{
	Position initial_position(-1, 5);
	Pawn pawn(initial_position);

	EXPECT_EQ(pawn.getCurrentPosition().row, 0);
	EXPECT_EQ(pawn.getCurrentPosition().column, 0);
}
TEST(PawnTestCase, ConstructorTest4)
{
	Position initial_position(4, -1);
	Pawn pawn(initial_position);

	EXPECT_EQ(pawn.getCurrentPosition().row, 0);
	EXPECT_EQ(pawn.getCurrentPosition().column, 0);
}
TEST(PawnTestCase, ConstructorTest5)
{
	Position initial_position(9, 2);
	Pawn pawn(initial_position);

	EXPECT_EQ(pawn.getCurrentPosition().row, 0);
	EXPECT_EQ(pawn.getCurrentPosition().column, 0);
}
TEST(PawnTestCase, ConstructorTest6)
{
	Position initial_position(2, 9);
	Pawn pawn(initial_position);

	EXPECT_EQ(pawn.getCurrentPosition().row, 0);
	EXPECT_EQ(pawn.getCurrentPosition().column, 0);
}
TEST(PawnTestCase, MovingTest1)
{
	Position initial_position(1, 1);
	Pawn pawn(initial_position);

	Position new_position(2, 3);
	pawn.move(new_position);

	EXPECT_EQ(pawn.getCurrentPosition().row, 2);
	EXPECT_EQ(pawn.getCurrentPosition().column, 3);
}
TEST(PawnTestCase, MovingTest2)
{
	Position initial_position(1, 1);
	Pawn pawn(initial_position);

	Position new_position(1, 5);
	pawn.move(new_position);

	EXPECT_EQ(pawn.getCurrentPosition().row, 1);
	EXPECT_EQ(pawn.getCurrentPosition().column, 5);
}
TEST(PawnTestCase, PossibleMovements1)
{
	//3 Possible movements available
	Position initial_position(1, 0);
	Pawn pawn(initial_position);

	Position opponent(2, 1);
	std::vector<Position> opponent_pieces;
	std::vector<Position> self_pieces;

	opponent_pieces.push_back(opponent);

	std::vector<Position> possible_movements = pawn.getPossibleMovements(self_pieces, opponent_pieces);
	EXPECT_EQ(int(possible_movements.size()), 3);

	Position m1(2, 0);
	Position m2(2, 1);
	Position m3(3, 0);

	std::vector<Position>::iterator iterator;

	iterator = std::find(possible_movements.begin(), possible_movements.end(), m1);
	bool found_m1 = (iterator != std::end(possible_movements));
	EXPECT_EQ(found_m1, true);

	iterator = std::find(possible_movements.begin(), possible_movements.end(), m2);
	bool found_m2 = (iterator != std::end(possible_movements));
	EXPECT_EQ(found_m2, true);

	iterator = std::find(possible_movements.begin(), possible_movements.end(), m3);
	bool found_m3 = (iterator != std::end(possible_movements));
	EXPECT_EQ(found_m3, true);

}
TEST(PawnTestCase, PossibleMovements2)
{
	//1 Possible movements available
	Position initial_position(0, 0);
	Pawn pawn(initial_position);
	Position second_position(5, 4);
	pawn.move(second_position);

	std::vector<Position> opponent_pieces;
	std::vector<Position> self_pieces;

	std::vector<Position> possible_movements = pawn.getPossibleMovements(self_pieces, opponent_pieces);
	EXPECT_EQ(int(possible_movements.size()), 1);

	Position m1(4, 4);

	std::vector<Position>::iterator iterator;

	iterator = std::find(possible_movements.begin(), possible_movements.end(), m1);
	bool found_m1 = (iterator != std::end(possible_movements));
	EXPECT_EQ(found_m1, true);

}
TEST(PawnTestCase, PossibleMovements3)
{
	//No Possible movements available
	Position initial_position(3, 2);
	Pawn pawn(initial_position);
	Position second_position(4, 2);
	pawn.move(second_position);

	Position opponent(3, 2);

	std::vector<Position> opponent_pieces;
	std::vector<Position> self_pieces;
	opponent_pieces.push_back(opponent);

	std::vector<Position> possible_movements = pawn.getPossibleMovements(self_pieces, opponent_pieces);
	EXPECT_EQ(int(possible_movements.size()), 0);
}