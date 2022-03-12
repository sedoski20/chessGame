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
	virtual bool move(Position position);
	static bool hasPieceOnPosition(const std::list<Position>& pieces, const Position position);
	virtual Position getCurrentPosition() const;
	virtual std::list<Position> getPossibleMovements(BoardPositions &board) const = 0;
													  
	PieceType getType() const { return type; }

};

#endif //PIECE_H