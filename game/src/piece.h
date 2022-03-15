#ifndef PIECE_H
#define PIECE_H

#include "position.h"
#include "boardpositions.h"
#include <string>
#include <list>

enum class MovementDirection
{
	MOVING_UP,
	MOVING_DOWN
};

enum class PieceType
{
	ROOK,
	KNIGHT,
	BISHOP, 
	QUEEN,
	KING,
	PAWN
};

class Piece
{

protected: 
	Position currentPosition;
	PieceType type;

public: 
	Piece(Position initialPostion);
	static bool hasPieceOnPosition(const std::list<Position>& pieces, const Position position);
	bool move(Position position);
	PieceType getType() const { return type; }
	Position getCurrentPosition() const;

	virtual std::list<Position> getPossibleMovements(const BoardPositions &board) const = 0;
};

#endif //PIECE_H