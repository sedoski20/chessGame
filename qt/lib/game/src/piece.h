#ifndef PIECE_H
#define PIECE_H

#include "position.h"
#include <string>
#include <vector>
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
	Piece();
	Piece(Position initialPostion);
	static bool hasPieceOnPosition(const std::list<Position>& pieces, const Position position);
	static bool hasPieceOnPosition(const std::list<Position*>& pieces, const Position position);
	void destroy();
	virtual bool move(Position position);
	virtual Position getCurrentPosition();
	virtual std::list<Position> getPossibleMovements(const std::list<Position> & selfPieces,
													   const std::list<Position> & opponentPieces) = 0;

	PieceType getType() const { return type; }

};

#endif //PIECE_H