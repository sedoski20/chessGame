#ifndef BOARDENGINE_H
#define BOARDENGINE_H

#include "boardpositions.h"
#include "piece.h"
#include "playermanager.h"

class BoardEngine
{
private:
    const PlayerManager *players;
    void removeUnsafeMovements(std::list<Position> &movements, const Piece* targetPiece) const;
    BoardPositions getNewArrangementFromMovement(Position targetPosition, const Piece* targetPiece) const;
    
public:
    BoardEngine(const PlayerManager *players);

    BoardPositions getBoardPositions() const;
    std::list<Position> getPossibleMovements(const Piece *piece) const;
    bool isCheckArrangement(const BoardPositions arrangement, Position kingPosition) const; 
    bool isCheckmate() const;
};

#endif // BOARDENGINE_H
