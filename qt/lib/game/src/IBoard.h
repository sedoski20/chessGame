#ifndef IBOARD_H
#define IBOARD_H

#include <list>
#include "position.h"
#include "iplayer.h"

enum class PlayerTurn
{
    TURN_PLAYER1,
    TURN_PLAYER2
};


class IBoard
{

public:
	virtual std::list<PieceInfo> getPlayer1Pieces() = 0;
	virtual std::list<PieceInfo> getPlayer2Pieces() = 0;
	virtual std::list<PositionStatus> getBoardStatus() = 0;
	virtual void setPlayer1Pieces(std::list<PieceInfo> & pieces) = 0;
	virtual void setPlayer2Pieces(std::list<PieceInfo> & pieces) = 0;
	virtual void resetBoardStatus() = 0;
	virtual void addCheckToBoardStatus(Position & position) = 0;
	virtual void updateBoardStatus() = 0;
	virtual bool isCheckmate() = 0;
	virtual bool isPossibleMovement(Position &destination) = 0;
	virtual PlayerTurn getTurn() const = 0;
    virtual void setTurn(const PlayerTurn &turn_) = 0;
};


#endif // IBOARD_H

