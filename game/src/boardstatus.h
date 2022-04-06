#ifndef BOARDSTATUS_H
#define BOARDSTATUS_H

#include "positionstatus.h"
#include "boardpositions.h"
#include "boardengine.h"
#include "piece.h"
#include <list>

class BoardStatus
{
private:
    const PlayerManager *players;
    std::list<PositionStatus> boardStatus;

    void addPossibleMovements(const Piece *selectedPiece);
    void addSelectedPiece(const Piece *selectedPiece); 
    void addCheck();

public:
    BoardStatus(const PlayerManager *players);
    void reset();
    void update(const Piece *selectedPiece);
    std::list<PositionStatus> getHighlightedPositions() const;
    std::list<const Piece*> getPlayer1Pieces() const;
    std::list<const Piece*> getPlayer2Pieces() const;
};


#endif // BOARDSTATUS_H
