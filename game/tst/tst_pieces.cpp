#include <gtest/gtest.h>
#include <algorithm>
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

TEST(PieceTestCase, find1)
{
	Piece* m1 = new Pawn(Position(2,3));
	Piece* m2 = new Rook(Position(2,0));
	Piece* m3 = new Queen(Position(2,1));

	std::list<Piece *> pieces;
	pieces.push_back(m1);
	pieces.push_back(m2);
	pieces.push_back(m3);

	Position check(2,0);

	Piece *result = Piece::find(pieces, check);
	EXPECT_EQ(result->getType(), PieceType::ROOK);
	EXPECT_EQ(result->getPosition(), check);

	delete m1;
	delete m2;
	delete m3;
}
TEST(PawnTestCase, ConstructorTest1)
{
	Position initial_position(0, 0);
	Pawn pawn(initial_position);
	
	EXPECT_EQ(pawn.getPosition().row, 0);
	EXPECT_EQ(pawn.getPosition().column, 0);
}
TEST(PawnTestCase, ConstructorTest2)
{
	Position initial_position(4, 5);
	Pawn pawn(initial_position); 	

	EXPECT_EQ(pawn.getPosition().row, 4);
	EXPECT_EQ(pawn.getPosition().column, 5);
}
TEST(PawnTestCase, PossibleMovements1)
{
	//3 Possible movements available
	Position initial_position(1, 0);
	Pawn pawn(initial_position);

	Position opponent(2, 1);
	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	opponent_pieces.push_back(opponent);

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = pawn.getPossibleMovements(board);
	EXPECT_EQ(int(possible_movements.size()), 3);

	Position m1(2, 0);
	Position m2(2, 1);
	Position m3(3, 0);

	std::list<Position>::iterator iterator;

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
	EXPECT_EQ(pawn.move(second_position), true);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;
	
	BoardPositions board(self_pieces, opponent_pieces);	
	std::list<Position> possible_movements = pawn.getPossibleMovements(board);
	EXPECT_EQ(int(possible_movements.size()), 1);

	Position m1(4, 4);

	std::list<Position>::iterator iterator;

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
	EXPECT_EQ(pawn.move(second_position), true);

	Position opponent(3, 2);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;
	opponent_pieces.push_back(opponent);

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = pawn.getPossibleMovements(board);
	EXPECT_EQ(int(possible_movements.size()), 0);
}
TEST(RookTestCase, ConstructorTest1)
{
	Position initial_position(3, 2);
	Rook rook(initial_position);

	EXPECT_EQ(rook.getPosition().row, 3);
	EXPECT_EQ(rook.getPosition().column, 2);
}
TEST(RookTestCase, PossibleMovements1)
{
	Position initial_position(3, 2);
	Rook rook(initial_position);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = rook.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

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

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	self_pieces.push_back(Position(7, 4));
	self_pieces.push_back(Position(2, 4));
	opponent_pieces.push_back(Position(5, 2));
	opponent_pieces.push_back(Position(5, 7));

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = rook.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

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
	}
}
TEST(RookTestCase, PossibleMovements3)
{
	Position initial_position(2, 2);
	Rook rook(initial_position);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	opponent_pieces.push_back(Position(1, 2));
	opponent_pieces.push_back(Position(2, 1));
	opponent_pieces.push_back(Position(3, 2));
	opponent_pieces.push_back(Position(2, 3));
	
	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = rook.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

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
	}
}
TEST(KnightTestCase, ConstructorTest1)
{
	Position initial_position(3, 2);
	Knight knight(initial_position);

	EXPECT_EQ(knight.getPosition().row, 3);
	EXPECT_EQ(knight.getPosition().column, 2);
}
TEST(KnightTestCase, PossibleMovements1)
{
	Position initial_position(2, 2);
	Knight knight(initial_position);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = knight.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 8);

	std::list<Position> expected;
	expected.push_back(Position(0,1));
	expected.push_back(Position(0,3));
	expected.push_back(Position(1,0));
	expected.push_back(Position(1,4));
	expected.push_back(Position(3,0));
	expected.push_back(Position(3,4));
	expected.push_back(Position(4,1));
	expected.push_back(Position(4,3));

	for(Position pos : expected)
	{
		iterator = std::find(possible_movements.begin(), possible_movements.end(), pos);
		bool result = (iterator != std::end(possible_movements));
	}
}
TEST(KnightTestCase, PossibleMovements2)
{
	Position initial_position(2, 2);
	Knight knight(initial_position);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	self_pieces.push_back(Position(4,1));
	self_pieces.push_back(Position(3,4));

	opponent_pieces.push_back(Position(1,0));
	
	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = knight.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 6);

	std::list<Position> expected;
	expected.push_back(Position(0,1));
	expected.push_back(Position(0,3));
	expected.push_back(Position(1,4));
	expected.push_back(Position(3,0));
	expected.push_back(Position(4,3));

	for(Position pos : expected)
	{
		iterator = std::find(possible_movements.begin(), possible_movements.end(), pos);
		bool result = (iterator != std::end(possible_movements));

		EXPECT_EQ(result, true);
	}
}
TEST(KnightTestCase, PossibleMovements3)
{
	Position initial_position(2, 2);
	Knight knight(initial_position);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	self_pieces.push_back(Position(0,1));
	self_pieces.push_back(Position(0,3));
	self_pieces.push_back(Position(1,0));
	self_pieces.push_back(Position(1,4));
	self_pieces.push_back(Position(3,0));
	self_pieces.push_back(Position(3,4));
	self_pieces.push_back(Position(4,1));
	self_pieces.push_back(Position(4,3));

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = knight.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 0);
}
TEST(KnightTestCase, PossibleMovements4)
{
	Position initial_position(1, 2);
	Knight knight(initial_position);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = knight.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 6);

	std::list<Position> expected;
	expected.push_back(Position(0,0));
	expected.push_back(Position(0,4));
	expected.push_back(Position(2,0));
	expected.push_back(Position(2,4));
	expected.push_back(Position(3,1));
	expected.push_back(Position(3,3));

	for(Position pos : expected)
	{
		iterator = std::find(possible_movements.begin(), possible_movements.end(), pos);
		bool result = (iterator != std::end(possible_movements));

		EXPECT_EQ(result, true);
	}
}
TEST(KnightTestCase, PossibleMovements5)
{
	Position initial_position(1, 2);
	Knight knight(initial_position);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	self_pieces.push_back(Position(2,0));
	self_pieces.push_back(Position(3,1));

	opponent_pieces.push_back(Position(0,4));
	opponent_pieces.push_back(Position(2,4));

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = knight.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 4);

	std::list<Position> expected;
	expected.push_back(Position(0,0));
	expected.push_back(Position(0,4));
	expected.push_back(Position(2,4));
	expected.push_back(Position(3,3));

	for(Position pos : expected)
	{
		iterator = std::find(possible_movements.begin(), possible_movements.end(), pos);
		bool result = (iterator != std::end(possible_movements));

		EXPECT_EQ(result, true);
	}
}
TEST(BishopTestCase, ConstructorTest1)
{
	Position initial_position(4, 3);
	Bishop bishop(initial_position);

	EXPECT_EQ(bishop.getPosition().row, 4);
	EXPECT_EQ(bishop.getPosition().column, 3);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = bishop.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 13);

}
TEST(BishopTestCase, PossibleMovements1)
{
	Position initial_position(4, 3);
	Bishop bishop(initial_position);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = bishop.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 13);

	std::list<Position> expected;
	expected.push_back(Position(1,0));
	expected.push_back(Position(2,1));
	expected.push_back(Position(3,2));
	expected.push_back(Position(5,4));
	expected.push_back(Position(6,5));
	expected.push_back(Position(7,6));
	expected.push_back(Position(7,0));
	expected.push_back(Position(6,1));
	expected.push_back(Position(5,2));
	expected.push_back(Position(3,4));
	expected.push_back(Position(2,5));
	expected.push_back(Position(1,6));
	expected.push_back(Position(0,7));

	for(Position pos : expected)
	{
		iterator = std::find(possible_movements.begin(), possible_movements.end(), pos);
		bool result = (iterator != std::end(possible_movements));

		EXPECT_EQ(result, true);
	}
}
TEST(BishopTestCase, PossibleMovements2)
{
	Position initial_position(4, 3);
	Bishop bishop(initial_position);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	opponent_pieces.push_back(Position(3,2));
	self_pieces.push_back(Position(7,0));
	self_pieces.push_back(Position(7,6));

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = bishop.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 9);

	std::list<Position> expected;
	expected.push_back(Position(3,2));
	expected.push_back(Position(5,4));
	expected.push_back(Position(6,5));
	expected.push_back(Position(6,1));
	expected.push_back(Position(5,2));
	expected.push_back(Position(3,4));
	expected.push_back(Position(2,5));
	expected.push_back(Position(1,6));
	expected.push_back(Position(0,7));

	for(Position pos : expected)
	{
		iterator = std::find(possible_movements.begin(), possible_movements.end(), pos);
		bool result = (iterator != std::end(possible_movements));

		EXPECT_EQ(result, true);
	}
}
TEST(BishopTestCase, PossibleMovements3)
{
	Position initial_position(0, 0);
	Bishop bishop(initial_position);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	opponent_pieces.push_back(Position(6,6));

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = bishop.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 6);

	std::list<Position> expected;
	expected.push_back(Position(1,1));
	expected.push_back(Position(2,2));
	expected.push_back(Position(3,3));
	expected.push_back(Position(4,4));
	expected.push_back(Position(5,5));
	expected.push_back(Position(6,6));

	for(Position pos : expected)
	{
		iterator = std::find(possible_movements.begin(), possible_movements.end(), pos);
		bool result = (iterator != std::end(possible_movements));

		EXPECT_EQ(result, true);
	}
}
TEST(QueenTestCase, ConstructorTest1)
{
	Position initial_position(4, 3);
	Queen queen(initial_position);

	EXPECT_EQ(queen.getPosition().row, 4);
	EXPECT_EQ(queen.getPosition().column, 3);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = queen.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 27);
}
TEST(QueenTestCase, PossibleMovements1)
{
	Position initial_position(0, 1);
	Queen queen(initial_position);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	self_pieces.push_back(Position(0,6));
	self_pieces.push_back(Position(1,0));
	self_pieces.push_back(Position(3,4));
	opponent_pieces.push_back(Position(7,1));

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = queen.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 14);

	std::list<Position> expected;
	expected.push_back(Position(0,0));
	expected.push_back(Position(1,1));
	expected.push_back(Position(2,1));
	expected.push_back(Position(3,1));
	expected.push_back(Position(4,1));
	expected.push_back(Position(5,1));
	expected.push_back(Position(6,1));
	expected.push_back(Position(7,1));
	expected.push_back(Position(1,2));
	expected.push_back(Position(2,3));
	expected.push_back(Position(0,2));
	expected.push_back(Position(0,3));
	expected.push_back(Position(0,4));
	expected.push_back(Position(0,5));

	for(Position pos : expected)
	{
		iterator = std::find(possible_movements.begin(), possible_movements.end(), pos);
		bool result = (iterator != std::end(possible_movements));

		EXPECT_EQ(result, true);
	}
}
TEST(QueenTestCase, PossibleMovements2)
{
	Position initial_position(3, 2);
	Queen queen(initial_position);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	self_pieces.push_back(Position(5,0));
	self_pieces.push_back(Position(1,0));
	self_pieces.push_back(Position(3,4));
	opponent_pieces.push_back(Position(5,2));
	opponent_pieces.push_back(Position(5,4));
	opponent_pieces.push_back(Position(1,4));

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = queen.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 14);

	std::list<Position> expected;
	expected.push_back(Position(0,2));
	expected.push_back(Position(1,2));
	expected.push_back(Position(1,4));
	expected.push_back(Position(2,1));
	expected.push_back(Position(2,2));
	expected.push_back(Position(2,3));
	expected.push_back(Position(3,0));
	expected.push_back(Position(3,1));
	expected.push_back(Position(3,3));
	expected.push_back(Position(4,1));
	expected.push_back(Position(4,2));
	expected.push_back(Position(4,3));
	expected.push_back(Position(5,2));
	expected.push_back(Position(5,4));

	for(Position pos : expected)
	{
		iterator = std::find(possible_movements.begin(), possible_movements.end(), pos);
		bool result = (iterator != std::end(possible_movements));

		EXPECT_EQ(result, true);
	}
}
TEST(KingTestCase, ConstructorTest1)
{
	Position initial_position(4, 3);
	King king(initial_position);

	EXPECT_EQ(king.getPosition().row, 4);
	EXPECT_EQ(king.getPosition().column, 3);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = king.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 8);
}
TEST(KingTestCase, PossibleMovements1)
{
	Position initial_position(2, 2);
	King king(initial_position);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	self_pieces.push_back(Position(3,2));
	self_pieces.push_back(Position(2,3));
	opponent_pieces.push_back(Position(2,1));

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = king.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 6);

	std::list<Position> expected;
	expected.push_back(Position(1,1));
	expected.push_back(Position(1,2));
	expected.push_back(Position(1,3));
	expected.push_back(Position(2,1));
	expected.push_back(Position(3,1));
	expected.push_back(Position(3,3));

	for(Position pos : expected)
	{
		iterator = std::find(possible_movements.begin(), possible_movements.end(), pos);
		bool result = (iterator != std::end(possible_movements));

		EXPECT_EQ(result, true);
	}
}
TEST(KingTestCase, PossibleMovements2)
{
	Position initial_position(1, 0);
	King king(initial_position);

	std::list<Position> opponent_pieces;
	std::list<Position> self_pieces;

	self_pieces.push_back(Position(0,1));
	self_pieces.push_back(Position(1,1));
	opponent_pieces.push_back(Position(0,0));
	opponent_pieces.push_back(Position(2,1));

	BoardPositions board(self_pieces, opponent_pieces);
	std::list<Position> possible_movements = king.getPossibleMovements(board);
	std::list<Position>::iterator iterator;

	EXPECT_EQ(possible_movements.size(), 3);

	std::list<Position> expected;
	expected.push_back(Position(0,0));
	expected.push_back(Position(2,0));
	expected.push_back(Position(2,1));

	for(Position pos : expected)
	{
		iterator = std::find(possible_movements.begin(), possible_movements.end(), pos);
		bool result = (iterator != std::end(possible_movements));

		EXPECT_EQ(result, true);
	}
}
TEST(PieceTestCase, InvalidMovement1)
{
	Position initial_position(1, 0);
	Pawn pawn(initial_position);

	EXPECT_EQ(pawn.getPosition(), initial_position);
	
	Position new_position(2, 8);
	EXPECT_EQ(pawn.move(new_position), false);

	EXPECT_EQ(pawn.getPosition(), initial_position);
}
TEST(PieceTestCase, InvalidMovement2)
{
	Position initial_position(1, 0);
	Pawn pawn(initial_position);

	EXPECT_EQ(pawn.getPosition(), initial_position);
	
	Position new_position(8, 2);
	EXPECT_EQ(pawn.move(new_position), false);

	EXPECT_EQ(pawn.getPosition(), initial_position);
}
TEST(PieceTestCase, InvalidMovement3)
{
	Position initial_position(1, 0);
	Pawn pawn(initial_position);

	EXPECT_EQ(pawn.getPosition(), initial_position);
	
	Position new_position(-1, 2);
	EXPECT_EQ(pawn.move(new_position), false);

	EXPECT_EQ(pawn.getPosition(), initial_position);
}
TEST(PieceTestCase, InvalidMovement4)
{
	Position initial_position(1, 0);
	Pawn pawn(initial_position);

	EXPECT_EQ(pawn.getPosition(), initial_position);
	
	Position new_position(-1, 2);
	EXPECT_EQ(pawn.move(new_position), false);

	EXPECT_EQ(pawn.getPosition(), initial_position);
}
TEST(PieceTestCase, MovingPanw)
{
	Position initial_position(1, 1);
	Pawn pawn(initial_position);

	EXPECT_EQ(pawn.getPosition(), initial_position);
	
	Position new_position(2, 3);
	EXPECT_EQ(pawn.move(new_position), true);

	EXPECT_EQ(pawn.getPosition(), new_position);
}
TEST(PieceTestCase, MovingBishop)
{
	Position initial_position(7, 7);
	Bishop bishop(initial_position);

	EXPECT_EQ(bishop.getPosition(), initial_position);
	
	Position new_position(5, 4);
	EXPECT_EQ(bishop.move(new_position), true);

	EXPECT_EQ(bishop.getPosition(), new_position);
}
TEST(PieceTestCase, MovingKnight)
{
	Position initial_position(1, 1);
	Knight knight(initial_position);

	EXPECT_EQ(knight.getPosition(), initial_position);
	
	Position new_position(1, 5);
	EXPECT_EQ(knight.move(new_position), true);

	EXPECT_EQ(knight.getPosition(), new_position);
}
TEST(PieceTestCase, MovingRook)
{
	Position initial_position(4, 1);
	Rook rook(initial_position);

	EXPECT_EQ(rook.getPosition(), initial_position);
	
	Position new_position(6, 4);
	EXPECT_EQ(rook.move(new_position), true);

	EXPECT_EQ(rook.getPosition(), new_position);
}
TEST(PieceTestCase, MovingQueen)
{
	Position initial_position(3, 3);
	Queen queen(initial_position);

	EXPECT_EQ(queen.getPosition(), initial_position);

	Position new_position(5, 6);
	EXPECT_EQ(queen.move(new_position), true);

	EXPECT_EQ(queen.getPosition(), new_position);
}
TEST(PieceTestCase, MovingKing)
{
	Position initial_position(1, 0);
	King king(initial_position);

	EXPECT_EQ(king.getPosition(), initial_position);
	
	Position new_position(2, 2);
	EXPECT_EQ(king.move(new_position), true);

	EXPECT_EQ(king.getPosition(), new_position);
}
TEST(PieceTestCase, getType)
{
	Piece * piece;
	Position initial_position(0,0);
	
	Pawn pawn(initial_position);
	Bishop bishop(initial_position);
	Rook rook(initial_position);
	Knight knight(initial_position);
	Queen queen(initial_position);
	King king(initial_position);

	piece = &pawn;
	EXPECT_EQ(piece->getType(), PieceType::PAWN); 

	piece = &bishop;
	EXPECT_EQ(piece->getType(), PieceType::BISHOP); 

	piece = &rook;
	EXPECT_EQ(piece->getType(), PieceType::ROOK); 

	piece = &knight;
	EXPECT_EQ(piece->getType(), PieceType::KNIGHT); 

	piece = &queen;
	EXPECT_EQ(piece->getType(), PieceType::QUEEN);
	 
	piece = &king;
	EXPECT_EQ(piece->getType(), PieceType::KING);
}
TEST(PieceTestCase, getPosition)
{
	Piece * piece;
	Position initial_position(0,0);
	
	Pawn pawn(initial_position);
	Bishop bishop(initial_position);
	Rook rook(initial_position);
	Knight knight(initial_position);
	Queen queen(initial_position);
	King king(initial_position);

	piece = &pawn;
	EXPECT_EQ(piece->getPosition(), initial_position); 

	piece = &bishop;
	EXPECT_EQ(piece->getPosition(), initial_position);

	piece = &rook;
	EXPECT_EQ(piece->getPosition(), initial_position);

	piece = &knight;
	EXPECT_EQ(piece->getPosition(), initial_position);

	piece = &queen;
	EXPECT_EQ(piece->getPosition(), initial_position);
	 
	piece = &king;
	EXPECT_EQ(piece->getPosition(), initial_position);
}