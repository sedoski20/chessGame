#ifndef PLAYER_H
#define PLAYER_H

#include "iplayer.h"
#include "piece.h"

class Player : IPlayer
{

private:
    std::vector<Piece*> pieces;
    std::string name;
    int score;
    int activePieces;

    void createPawns(int referenceRow);
    void createRooks(int referenceRow);
    void createKnights(int referenceRow);
    void createBishops(int referenceRow);
    void createQueen(int referenceRow);
    void createKing(int referenceRow);

public:
    Player(MovementDirection direction, std::string playerName);
    bool selectPiece(Position position);
    bool movePiece(Position position);
    void updateScore();

    //Getters and setters
    std::string getName() const { return name; }
    void setName(const std::string &name_) { name = name_; }

    int getActivePieces() const { return activePieces; }
    void setActivePieces(int activePieces_) { activePieces = activePieces_; }

    std::vector<Piece *> getPieces() const;
};




#endif //PLAYER_H