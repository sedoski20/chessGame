#ifndef BOARD_H
#define BOARD_H

#include "iboard.h"
#include "iplayer.h"

class Board : public IBoard
{

private:
    std::list<Position> player1Pieces;
    std::list<Position> player2Pieces;
    std::list<PositionStatus> boardStatus;

public:
    Board();    
    std::list<Position> getPlayer1Positions() { return player1Pieces; }
    void setPlayer1Positions(std::list<Position> & positions) { player1Pieces = positions; }

    std::list<Position> getPlayer2Positions() { return player2Pieces; }
    void setPlayer2Positions(std::list<Position> & positions) { player2Pieces = positions; }

    std::list<PositionStatus> getBoardStatus ();
    void updateBoardStatus(std::list<Position> & possibeMovements);
    
    void resetBoardStatus();
};


#endif // BOARD_H
