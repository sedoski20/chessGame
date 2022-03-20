#ifndef PLAYER_H
#define PLAYER_H

#include "iplayer.h"
#include "piece.h"

class Player : public IPlayer
{

private:
    std::list<Piece*> pieces;
    void createPawns(int referenceRow);
    void createRooks(int referenceRow);
    void createKnights(int referenceRow);
    void createBishops(int referenceRow);
    void createQueen(int referenceRow);
    void createKing(int referenceRow);

public:
    Player(MovementDirection direction);
    //TODO: create destructor to deallocate memory
    
    //TODO: solve unsafe modification on Piece object by calling Piece pointer methods outside from Player class	
    //      e.g: piece->move(Position(0,0)) can be called anywhere from a piece object pointer and them modify this object pointer. 
    const std::list<const Piece *> getPieces() const;
    bool capturePiece(Position target);
    bool movePiece(Position destination, Position from);
    Piece* findPiece(Position location) const; 
    
    Position getKingPosition() const;

};

#endif //PLAYER_H