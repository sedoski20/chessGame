#include "piece.h"
#include "algorithm"


Piece::Piece()
{
	Position default_position;
	this->currentPosition = default_position;
}

Piece::Piece(Position initialPostion)
{
	this->currentPosition = initialPostion;
}

bool Piece::hasPieceOnPosition(const std::vector<Position>& pieces, const Position position) 
{
	// Here, we have to use "auto" because the result of std::find for a const std::vector<Position> list
	//is a std::vector<Position>::const_iterator and it is not convertible to std::vector<Position>::iterator
	auto  iterator = std::find(pieces.begin(), pieces.end(), position);
	bool found_m1 = (iterator != std::end(pieces));

	return found_m1;
}

bool Piece::hasPieceOnPosition(const std::vector<Position*>& pieces, const Position position) 
{
	std::vector<Position> positions;
	for(Position *pos : pieces)
		positions.push_back(*pos);

	// Here, we have to use "auto" because the result of std::find for a const std::vector<Position> list
	//is a std::vector<Position>::const_iterator and it is not convertible to std::vector<Position>::iterator
	auto  iterator = std::find(positions.begin(), positions.end(), position);
	bool found_m1 = (iterator != std::end(positions));

	return found_m1;
}

Position Piece::getCurrentPosition()
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

void Piece::destroy()
{
}

