#include "position.h"
#include <string>
#include <vector>

#pragma once


class Piece
{

protected: 
	Position currentPosition;

public: 
	Piece();
	Piece(Position initialPostion);
	Position getCurrentPosition();
	bool move(Position positon);
	void destroy();
	virtual std::vector<Position> getPossibleMovements(const std::vector<Position> & selfPieces,
													   const std::vector<Position> & opponentPieces) = 0;
};

