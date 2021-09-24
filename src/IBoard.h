#ifndef IBOARD_H
#define IBOARD_H

#include <vector>
#include "position.h"

class IBoard
{

public:
	virtual std::vector<Position> getAvailablePositionsOnBoard() = 0;
	virtual int getValue() = 0;
	virtual void setValue(int value) = 0;
};


#endif // IBOARD_H
