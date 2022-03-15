#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : virtual public Piece
{
public:
	Pawn(Position initialPosition);
	std::list<Position> getPossibleMovements(const BoardPositions &board) const;

private:
	bool isFirstMovement;
	MovementDirection direction;
	
	void getPawnMovements(std::list<Position> & movements, const BoardPositions &board) const;
	void getPawnAtacks(std::list<Position> & movements, const BoardPositions &board) const;
	int getDirectionFactor() const;
};


#endif // PAWN_H
