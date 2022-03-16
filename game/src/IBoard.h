#ifndef IBOARD_H
#define IBOARD_H

#include <list>
#include "position.h"
#include "iplayer.h"

class IBoard
{
public:
	virtual void updateTurn() = 0;
	virtual void unslect() = 0;
	virtual bool isCheckmate() const = 0;
	virtual bool isCheckArrangement(const BoardPositions arrangement) const = 0;
	virtual bool isPieceSelected() const = 0;
	virtual bool select(Position &position) = 0;
    virtual bool moveSelectedPiece(Position position) = 0;
	virtual BoardPositions getBoardPositions() const = 0;
	virtual IPlayer* const getPlayer1() const = 0;
	virtual IPlayer* const getPlayer2() const = 0;
	virtual std::list<Position> getPossibleMovements() = 0;
};


#endif // IBOARD_H

