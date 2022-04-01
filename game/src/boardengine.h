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
    bool isCheckArrangement(const BoardPositions arrangement, Position kingPosition) const; 
    BoardPositions getNewArrangementFromMovement(Position targetPosition, const Piece* targetPiece) const;
    
public:
    BoardEngine(const PlayerManager *players);

    BoardPositions getBoardPositions() const;
    std::list<Position> getPossibleMovements(const Piece *selectedPiece) const;
    bool isCheck() const;
    bool isCheckMate() const;
    bool isAttack(Position target) const;
};

#endif // BOARDENGINE_H
