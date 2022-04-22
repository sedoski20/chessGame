#ifndef BOARDSTATUS_H
#define BOARDSTATUS_H

#include "positionstatus.h"
#include "boardpositions.h"
#include "boardengine.h"
#include "pieceinfo.h"
#include <list>

class BoardStatus
{
private:
    const BoardEngine *boardEngine;
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
    std::list<PieceInfo> getPlayer1Pieces() const;
    std::list<PieceInfo> getPlayer2Pieces() const;
};


#endif // BOARDSTATUS_H
