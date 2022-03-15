#include "piece.h"
#include "algorithm"

Piece::Piece(Position initialPostion)
{
	this->currentPosition = initialPostion;
}

Piece* Piece::find(const std::list<Piece *> pieces,  Piece &piece) 
{
	for(Piece * p : pieces)
	{
		bool same_type = (p->getType() == piece.getType());
		bool same_position = (p->getCurrentPosition() == piece.getCurrentPosition());

		if(same_type &&same_position)
			return p;
	}

	return NULL;
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


