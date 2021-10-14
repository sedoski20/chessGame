#ifndef PLAYER_H
#define PLAYER_H

#include "iplayer.h"
#include "piece.h"

class Player : public IPlayer
{

private:
    std::vector<Piece*> pieces;
    std::string name;
    Piece *selectedPiece;

    int score;
    int activePieces;

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

    bool getPossibleMovements(std::vector<Position> &opponentPieces, std::vector<Position> &possibleMovements);
    bool isPossibleMovement(std::vector<Position> &opponentPieces, Position destination);
    std::vector<Piece *> getPieces() const;
    std::vector<Position> getPositions();

    bool moveSelectedPiece(std::vector<Position> &opponentPieces, Position destination);
    bool receiveAttack(Position position);
    bool isAttack(Position position);
    void updateScore();

    //Getters and setters
    std::string getName() const { return name; }
    void setName(const std::string &name_) { name = name_; }

    Piece *getSelectedPiece() { return selectedPiece;}
    bool selectPiece(Position position);
    bool isPieceSelected();

    int getActivePieces() { return activePieces; }
    void setActivePieces(int activePieces_) { activePieces = activePieces_; }

};

#endif //PLAYER_H