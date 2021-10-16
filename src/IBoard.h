#ifndef IBOARD_H
#define IBOARD_H

#include <list>
#include "position.h"

class IBoard
{

public:
	virtual std::list<Position> getPlayer1Positions() = 0;
	virtual std::list<Position> getPlayer2Positions() = 0;
	virtual void setPlayer1Positions(std::list<Position> & positions) = 0;
	virtual void setPlayer2Positions(std::list<Position> & positions) = 0;
	virtual void resetBoardStatus() = 0;
	virtual void updateBoardStatus(std::list<Position> & possibeMovements) = 0;
};


#endif // IBOARD_H
