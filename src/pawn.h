#ifndef PAWN_H
#define PAWN_H

#include "piece.h"


enum class movementDirection
{
	MOVING_UP,
	MOVING_DOWN
};

class Pawn : public Piece
{
public:
	Pawn(Position intialPosition, movementDirection direction);
	std::vector<Position> getPossibleMovements(const std::vector<Position>& selfPieces, const std::vector<Position>& opponentPieces);
	bool move(Position positon);

private:
	bool isFirstMovement;
	movementDirection direction;
	
	void getPawnMovements(std::vector<Position> & movements, const std::vector<Position> & selfPieces, const std::vector<Position>& opponentPieces);
	void getPawnAtacks(std::vector<Position> & movements, const std::vector<Position> & opponentPieces);
	bool isSomePieceOnPosition(Position position, std::vector<Position> pieces);
	int getDirectionFactor();
};


#endif // PAWN_H
