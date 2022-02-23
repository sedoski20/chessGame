#ifndef IPLAYER_H
#define IPLAYER_H
#include "Piece.h"

struct PieceInfo
{
	Position position;
	PieceType type;
};

class IPlayer
{
private:
    
public:
    virtual int getActivePieces() = 0;
    virtual Piece *getSelectedPiece() = 0;
    virtual Position getKingPosition() = 0;
    virtual std::list<Position> getPositions() = 0;
    virtual std::list<PieceInfo> getPiecesInfo() = 0;
    virtual const std::list<Piece *> getPieces() = 0;
    virtual bool isPieceSelected() = 0;
    virtual bool selectPiece(Position position) = 0;
    virtual void unselectPiece() = 0;
    virtual bool getInCheck() const = 0;
    virtual void setInCheck(bool inCheck_) = 0;
    virtual bool isAttack(Position position) = 0;
    virtual bool receiveAttack(Position position) = 0;
    virtual bool moveSelectedPiece(std::list<Piece*> &opponentPieces, Position destination) = 0;
};


#endif //IPLAYER