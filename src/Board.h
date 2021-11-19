#ifndef BOARD_H
#define BOARD_H

#include "iboard.h"
#include "piece.h"
#include "iplayer.h"

//TODO: Move the business logic that needs data of all players from player class to the Board class
//TODO: Add a list of Piece * for each player

class Board : public IBoard
{

private:
    IPlayer *player1;
    IPlayer *player2;

    PlayerTurn turn;

    IPlayer *getCurrentPlayer();
    IPlayer *getOpponentPlayer();

    std::list<PieceInfo> player1Pieces;
    std::list<PieceInfo> player2Pieces;
    std::list<PositionStatus> boardStatus;

    std::list<Position> getPossibleMovementsForSelectedPiece();

public:
    Board(IPlayer *player1, IPlayer *player2);    
    std::list<PieceInfo> getPlayer1Pieces() { return player1Pieces; }
    void setPlayer1Pieces(std::list<PieceInfo> & pieces) { player1Pieces = pieces; }

    std::list<PieceInfo> getPlayer2Pieces() { return player2Pieces; }
    void setPlayer2Pieces(std::list<PieceInfo> & pieces) { player2Pieces = pieces; }

    std::list<PositionStatus> getBoardStatus ();
    void updateBoardStatus(PlayerTurn currentTurn);

    void addCheckToBoardStatus(Position & position);
    
    void resetBoardStatus();
};


#endif // BOARD_H
