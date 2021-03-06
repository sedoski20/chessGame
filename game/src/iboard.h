#ifndef IBOARD_H
#define IBOARD_H

#include <list>
#include "position.h"
#include "piece.h"
class IBoard
{
public:
	virtual ~IBoard() {}; 
	virtual bool isPieceSelected() const = 0;
	virtual bool select(Position &position) = 0;
    virtual bool moveSelectedPiece(Position position) = 0;
	virtual const Piece *getSelectedPiece() const = 0;
};

#endif // IBOARD_H

