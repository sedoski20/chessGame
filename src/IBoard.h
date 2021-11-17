#ifndef IBOARD_H
#define IBOARD_H

#include <list>
#include "position.h"
#include "iplayer.h"

class IBoard
{

public:
	virtual std::list<PieceInfo> getPlayer1Pieces() = 0;
	virtual std::list<PieceInfo> getPlayer2Pieces() = 0;
	virtual std::list<PositionStatus> getBoardStatus() = 0;
	virtual void setPlayer1Pieces(std::list<PieceInfo> & pieces) = 0;
	virtual void setPlayer2Pieces(std::list<PieceInfo> & pieces) = 0;
	virtual void resetBoardStatus() = 0;
	virtual void addCheckToBaordStatus(Position & position) = 0;
	virtual void updateBoardStatus(std::list<Position> & possibeMovements, std::list<Position> & opponnentPositions) = 0;
};


#endif // IBOARD_H

