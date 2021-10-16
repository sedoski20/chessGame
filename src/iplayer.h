#ifndef IPLAYER_H
#define IPLAYER_H
#include "Piece.h"

class IPlayer
{
private:
    
public:
    virtual int getActivePieces() = 0;
    virtual Piece *getSelectedPiece() = 0;
    virtual std::list<Position> getPositions() = 0;
    virtual bool isPieceSelected() = 0;
    virtual bool isAttack(Position position) = 0;
    virtual bool selectPiece(Position position) = 0;
    virtual bool receiveAttack(Position position) = 0;
    virtual bool moveSelectedPiece(std::list<Position> &opponentPieces, Position destination) = 0;
    virtual bool isPossibleMovement(std::list<Position> &opponentPieces, Position destination) = 0;
    virtual bool getPossibleMovements(std::list<Position> &opponentPieces, std::list<Position> &possibeMovements) = 0;
};


#endif //IPLAYER