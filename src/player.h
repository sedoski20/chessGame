#ifndef PLAYER_H
#define PLAYER_H

#include "iplayer.h"
#include "piece.h"

class Player : public IPlayer
{

private:
    std::list<Piece*> pieces;
    std::string name;
    Piece *selectedPiece;

    int score;
    int activePieces;
    bool inCheck;

    void createPawns(int referenceRow);
    void createRooks(int referenceRow);
    void createKnights(int referenceRow);
    void createBishops(int referenceRow);
    void createQueen(int referenceRow);
    void createKing(int referenceRow);

    bool findPiece(Position location, Piece *&piece);

public:
    Player(MovementDirection direction, std::string playerName);
    Player(MovementDirection direction);
    
    //TODO: solve unsafe modification on Piece object by calling Piece pointer methods outside from Player class	
    //      e.g: piece->move(Position(0,0)) can be called anywhere from a piece object pointer and them modify this object pointer. 
    const std::list<Piece *> getPieces();
    std::list<Position> getPositions();
    std::list<PieceInfo> getPiecesInfo();

    bool moveSelectedPiece(std::list<Piece *> &opponentPieces, Position destination);
    bool receiveAttack(Position position);
    bool isAttack(Position position);
    void updateScore();
    
    Position getKingPosition();

    //Getters and setters
    std::string getName() const { return name; }
    void setName(const std::string &name_) { name = name_; }

    Piece *getSelectedPiece() { return selectedPiece;}
    bool selectPiece(Position position);
    void unselectPiece();
    bool isPieceSelected();

    int getActivePieces() { return activePieces; }
    void setActivePieces(int activePieces_) { activePieces = activePieces_; }

    //TODO: move this implementation to board class
    bool getInCheck() const { return inCheck; }

};

#endif //PLAYER_H