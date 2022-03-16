#ifndef IPLAYER_H
#define IPLAYER_H
#include "piece.h"

class IPlayer
{
private:
    
public:
    virtual Piece* findPiece(Position location) const = 0;; 
    virtual const std::list<Piece *> getPieces() = 0;
    virtual bool capturePiece(Piece *piece) = 0;
    virtual bool movePiece(Position destination, Piece *piece) = 0;
    virtual Position getKingPosition() const = 0;
};


#endif //IPLAYER