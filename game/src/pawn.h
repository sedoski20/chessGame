#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : virtual public Piece
{
public:
	Pawn(Position initialPosition);
	std::list<Position> getPossibleMovements(const std::list<Position>& selfPieces, const std::list<Position>& opponentPieces) const;
	bool move(Position positon);

private:
	bool isFirstMovement;
	MovementDirection direction;
	
	void getPawnMovements(std::list<Position> & movements, const std::list<Position> & selfPieces, const std::list<Position>& opponentPieces) const;
	void getPawnAtacks(std::list<Position> & movements, const std::list<Position> & opponentPieces) const;
	bool isSomePieceOnPosition(Position position, std::list<Position> pieces) const;
	int getDirectionFactor() const;
};


#endif // PAWN_H
