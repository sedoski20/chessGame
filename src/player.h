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
    bool isPossibleMovement(std::list<Piece *> &opponentPieces, Position destination);
    void removeUnsafeMovements(std::list<Position> &movements, std::list<Piece *> opponentPieces);
    bool isCheckFromOpponent(const std::list<Position> &selfPositions, std::list<Piece *> &opponentPieces, Position kingPosition);

public:
    Player(MovementDirection direction, std::string playerName);
    Player(MovementDirection direction);

    bool getPossibleMovements(std::list<Piece *> &opponentPieces, std::list<Position> &possibleMovements);
    std::list<Piece *> getPieces();
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
    bool isPieceSelected();

    int getActivePieces() { return activePieces; }
    void setActivePieces(int activePieces_) { activePieces = activePieces_; }

    bool getInCheck() const { return inCheck; }

};

#endif //PLAYER_H