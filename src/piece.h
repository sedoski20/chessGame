#ifndef PIECE_H
#define PIECE_H

#include "position.h"
#include <string>
#include <vector>

enum class movementDirection
{
	MOVING_UP,
	MOVING_DOWN
};

class Piece
{

protected: 
	Position currentPosition;

public: 
	Piece();
	Piece(Position initialPostion);
	static bool hasPieceOnPosition(const std::vector<Position>& pieces, const Position position);
	void destroy();
	virtual bool move(Position positon);
	virtual Position getCurrentPosition();
	virtual std::vector<Position> getPossibleMovements(const std::vector<Position> & selfPieces,
													   const std::vector<Position> & opponentPieces) = 0;
};

#endif //PIECE_H