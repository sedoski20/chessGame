#include "piece.h"
#include "algorithm"

Piece::Piece(Position initialPostion)
{
	this->currentPosition = initialPostion;
}

bool Piece::hasPieceOnPosition(const std::list<Position>& pieces, const Position position) 
{
	// Here, we have to use "auto" because the result of std::find for a const std::list<Position> list
	//is a std::list<Position>::const_iterator and it is not convertible to std::list<Position>::iterator
	auto  iterator = std::find(pieces.begin(), pieces.end(), position);
	bool found_m1 = (iterator != std::end(pieces));

	return found_m1;
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


