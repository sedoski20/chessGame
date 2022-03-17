#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : virtual public Piece
{
public:
	Pawn(Position initialPosition);
	std::list<Position> getPossibleMovements(const BoardPositions &board) const;
    bool move(Position position);

private:
	bool isFirstMovement;
	MovementDirection direction;
	
	std::list<Position> getPawnMovements(const BoardPositions &board) const;
	std::list<Position> getPawnAtacks(const BoardPositions &board) const;
	int getDirectionFactor() const;
};


#endif // PAWN_H
