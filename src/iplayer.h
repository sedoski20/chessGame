#ifndef IPLAYER_H
#define IPLAYER_H
#include "Piece.h"

class IPlayer
{
private:
    
public:
    virtual int getActivePieces() = 0;
    virtual Piece *getSelectedPiece() = 0;
    virtual std::vector<Position> getPositions() = 0;
    virtual bool isPieceSelected() = 0;
    virtual bool isAttack(Position position) = 0;
    virtual bool selectPiece(Position position) = 0;
    virtual bool receiveAttack(Position position) = 0;
    virtual bool moveSelectedPiece(std::vector<Position> &opponentPieces, Position destination) = 0;
    virtual bool isPossibleMovement(std::vector<Position> &opponentPieces, Position destination) = 0;
    virtual bool getPossibleMovements(std::vector<Position> &opponentPieces, std::vector<Position> &possibeMovements) = 0;
};


#endif //IPLAYER