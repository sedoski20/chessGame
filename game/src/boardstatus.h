#ifndef BOARDSTATUS_H
#define BOARDSTATUS_H

#include "positionstatus.h"
#include "boardpositions.h"
#include "piece.h"
#include <list>


struct PieceInfo
{
	Position position;
	PieceType type;
};


class BoardStatus
{
private:
    std::list<PositionStatus> boardStatus;
    std::list<PieceInfo> player1PiecesInfo;
    std::list<PieceInfo> player2PiecesInfo;

public:
    BoardStatus();
    void reset();
    void addPiecesInfo(const std::list<Piece *> player1Pieces, const std::list<Piece *> player2Pieces);
    void addPossibleMovements(const std::list<Position> &possibleMovements, const BoardPositions &board);
    void addSelectedPiece(Position selectedPiece); 
    void addCheck(Position kingPosition);
    Status getStatus(Position position) const;
    std::list<PositionStatus> getBoardStatus() const;
    std::list<PieceInfo> getPlayer1PiecesInfo() const;
    std::list<PieceInfo> getPlayer2PiecesInfo() const;
};


#endif // BOARDSTATUS_H
