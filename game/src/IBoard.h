#ifndef IBOARD_H
#define IBOARD_H

#include <list>
#include "position.h"
#include "iplayer.h"
#include "boardstatus.h"

class IBoard
{
public:
	virtual void updateTurn() = 0;
	virtual void unslect() = 0;
	virtual bool isCheckmate() = 0;
	virtual bool isPieceSelected() const = 0;
	virtual bool select(Position &position) = 0;
    virtual bool moveSelectedPiece(Position position) = 0;
	virtual const BoardStatus getBoardStatus() const = 0;
	virtual void updateBoardStatus() = 0;
};

#endif // IBOARD_H

