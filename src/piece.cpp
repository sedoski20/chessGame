#include "piece.h"

Piece::Piece()
{
	Position default_position;
	this->currentPosition = default_position;
}

Piece::Piece(Position initialPostion)
{
	this->currentPosition = initialPostion;
}

Position Piece::getCurrentPosition()
{
	return currentPosition;
}

bool Piece::move(Position positon)
{
	this->currentPosition = positon;
	return false;
}

void Piece::destroy()
{
}

