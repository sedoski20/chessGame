#ifndef IBOARD_H
#define IBOARD_H

#include <vector>
#include "position.h"

class IBoard
{

public:
	virtual std::vector<Position> getPlayer1Positions() = 0;
	virtual std::vector<Position> getPlayer2Positions() = 0;
	virtual void setPlayer1Positions(std::vector<Position> & positions) = 0;
	virtual void setPlayer2Positions(std::vector<Position> & positions) = 0;
	virtual void resetBoardStatus() = 0;
	virtual void updateBoardStatus(std::vector<Position> & possibeMovements) = 0;
};


#endif // IBOARD_H
