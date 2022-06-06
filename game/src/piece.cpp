#include "piece.h"
#include "algorithm"

Piece::Piece(Position initialPostion, PieceType type) : position(initialPostion),
														type(type) {}


Position Piece::getPosition() const
{
	return this->position;
}

bool Piece::move(Position position)
{
	if (!position.isValidPosition())
		return false;

	this->position = position;
	return true;
}


