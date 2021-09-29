#include <gtest/gtest.h>
#include <algorithm>
#include "../src/pawn.h"
#include "../src/rook.h"

TEST(PieceTestCase, hasPieceOnPosition1)
{
	Position m1(2, 0);
	Position m2(2, 1);
	Position m3(3, 0);

	std::vector<Position> pieces;
	pieces.push_back(m1);
	pieces.push_back(m2);
	pieces.push_back(m3);

	Position check(2,0);

	bool result = Piece::hasPieceOnPosition(pieces, check);
	EXPECT_EQ(result, true);
}

TEST(PieceTestCase, hasPieceOnPosition2)
{
	Position m1(2, 0);
	Position m2(2, 1);
	Position m3(3, 0);

	std::vector<Position> pieces;
	pieces.push_back(m1);
	pieces.push_back(m2);
	pieces.push_back(m3);

	Position check(4,1);

	bool result = Piece::hasPieceOnPosition(pieces, check);
	EXPECT_EQ(result, false);
}

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

TEST(RookTestCase, ConstructorTest1)
{
	Position initial_position(3, 2);
	Rook rook(initial_position);

	EXPECT_EQ(rook.getCurrentPosition().row, 3);
	EXPECT_EQ(rook.getCurrentPosition().column, 2);
}

TEST(RookTestCase, PossibleMovements1)
{
	Position initial_position(3, 2);
	Rook rook(initial_position);

	std::vector<Position> opponent_pieces;
	std::vector<Position> self_pieces;

	std::vector<Position> possible_movements = rook.getPossibleMovements(self_pieces, opponent_pieces);
	std::vector<Position>::iterator iterator;

	//Horizontal check
	for(int i = 0; i < 8; i++)
	{
		if(i == 2)
			continue;

		Position expected(3, i);
		iterator = std::find(possible_movements.begin(), possible_movements.end(), expected);
		bool found_m1 = (iterator != std::end(possible_movements));
		EXPECT_EQ(found_m1, true);
	}

	//Vertical check
	for(int i = 0; i < 8; i++)
	{
		if(i == 3)
			continue;

		Position expected(i, 2);
		iterator = std::find(possible_movements.begin(), possible_movements.end(), expected);
		bool found_m1 = (iterator != std::end(possible_movements));
		EXPECT_EQ(found_m1, true);
	}
}

TEST(RookTestCase, PossibleMovements2)
{
	Position initial_position(5, 4);
	Rook rook(initial_position);

	std::vector<Position> opponent_pieces;
	std::vector<Position> self_pieces;

	self_pieces.push_back(Position(7, 4));
	self_pieces.push_back(Position(2, 4));
	opponent_pieces.push_back(Position(5, 2));
	opponent_pieces.push_back(Position(5, 7));

	std::vector<Position> possible_movements = rook.getPossibleMovements(self_pieces, opponent_pieces);
	std::vector<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 8);

	//Horizontal check
	for(int i = 0; i < 8; i++)
	{
		bool result = true;

		if(i < 2 || i == 4)
			result = false;

		Position expected(5, i);
		iterator = std::find(possible_movements.begin(), possible_movements.end(), expected);
		bool found_m1 = (iterator != std::end(possible_movements));
		EXPECT_EQ(found_m1, result);
		
		// std::cout << "Horizontal: " << std::endl;
		// std::cout << "Linha: " << expected.row << " Coluna: " << expected.column << " Result: " << result << std::endl;
	}

	//Vertical check
	for(int i = 0; i < 8; i++)
	{
		bool result = true;

		if(i <= 2 || i == 5 || i == 7)
			result = false;

		Position expected(i, 4);
		iterator = std::find(possible_movements.begin(), possible_movements.end(), expected);
		bool found_m1 = (iterator != std::end(possible_movements));
		EXPECT_EQ(found_m1, result);

		// std::cout << "Vertical: " << std::endl;
		// std::cout << "Linha: " << expected.row << " Coluna: " << expected.column << " Result: " << result << std::endl;
	}
}

TEST(RookTestCase, PossibleMovements3)
{
	Position initial_position(2, 2);
	Rook rook(initial_position);

	std::vector<Position> opponent_pieces;
	std::vector<Position> self_pieces;

	opponent_pieces.push_back(Position(1, 2));
	opponent_pieces.push_back(Position(2, 1));
	opponent_pieces.push_back(Position(3, 2));
	opponent_pieces.push_back(Position(2, 3));

	std::vector<Position> possible_movements = rook.getPossibleMovements(self_pieces, opponent_pieces);
	std::vector<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 4);

	//Horizontal check
	for(int i = 0; i < 8; i++)
	{
		bool result = true;

		if(i < 1 || i == 2 || i > 3)
			result = false;

		Position expected(2, i);
		iterator = std::find(possible_movements.begin(), possible_movements.end(), expected);
		bool found_m1 = (iterator != std::end(possible_movements));
		EXPECT_EQ(found_m1, result);
		
		// std::cout << "Horizontal: " << std::endl;
		// std::cout << "Linha: " << expected.row << " Coluna: " << expected.column << " Result: " << result << std::endl;
	}

	//Vertical check
	for(int i = 0; i < 8; i++)
	{
		bool result = true;

		if(i < 1 || i == 2 || i > 3)
			result = false;

		Position expected(i, 2);
		iterator = std::find(possible_movements.begin(), possible_movements.end(), expected);
		bool found_m1 = (iterator != std::end(possible_movements));
		EXPECT_EQ(found_m1, result);

		// std::cout << "Vertical: " << std::endl;
		// std::cout << "Linha: " << expected.row << " Coluna: " << expected.column << " Result: " << result << std::endl;
	}
}