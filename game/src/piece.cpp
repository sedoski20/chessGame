#include "piece.h"
#include "algorithm"

Piece::Piece(Position initialPostion)
{
	this->currentPosition = initialPostion;
}

Position Piece::getCurrentPosition() const
{
	return currentPosition;
}

bool Piece::move(Position position)
{
	if (!position.isValidPosition())
		return false;

	this->currentPosition = position;
	return true;
}


