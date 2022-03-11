#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : virtual public Piece
{
public:
	Pawn(Position initialPosition);
	std::list<Position> getPossibleMovements(const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces);
	bool move(Position positon);

private:
	bool isFirstMovement;
	MovementDirection direction;
	
	void getPawnMovements(std::list<Position> & movements, const std::list<Position> & selfPieces, const std::list<Position>& opponentPieces);
	void getPawnAtacks(std::list<Position> & movements, const std::list<Position> & opponentPieces);
	bool isSomePieceOnPosition(Position position, std::list<Position> pieces);
	int getDirectionFactor();
};


#endif // PAWN_H
