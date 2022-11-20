#ifndef IPLAYER_H
#define IPLAYER_H
#include "piece.h"

class IPlayer
{
private:
    
public:
    virtual ~IPlayer(){};
    virtual Piece* findPiece(Position location) const = 0;; 
    virtual const std::list<const Piece *> getPieces() const = 0;
    virtual bool capturePiece(Position target) = 0;
    virtual bool movePiece(Position destination, Position from) = 0;
    virtual Position getKingPosition() const = 0;
};


#endif //IPLAYER