#ifndef BOARD_H
#define BOARD_H

#include "iboard.h"

class Board : public IBoard
{

private:
    std::list<PieceInfo> player1Pieces;
    std::list<PieceInfo> player2Pieces;
    std::list<PositionStatus> boardStatus;

public:
    Board();    
    std::list<PieceInfo> getPlayer1Pieces() { return player1Pieces; }
    void setPlayer1Pieces(std::list<PieceInfo> & pieces) { player1Pieces = pieces; }

    std::list<PieceInfo> getPlayer2Pieces() { return player2Pieces; }
    void setPlayer2Pieces(std::list<PieceInfo> & pieces) { player2Pieces = pieces; }

    std::list<PositionStatus> getBoardStatus ();
    void updateBoardStatus(std::list<Position> & possibeMovements, std::list<Position> & opponnentPositions);
    
    void resetBoardStatus();
};


#endif // BOARD_H
