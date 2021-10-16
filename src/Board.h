#ifndef BOARD_H
#define BOARD_H

#include "iboard.h"
#include "iplayer.h"

enum class PositionStatus
{
    NORMAL,
    HIGHLIGHTED,
    ATTACK
};

class Board : public IBoard
{

private:
    std::list<Position> player1Pieces;
    std::list<Position> player2Pieces;
    std::list<PositionStatus> highlihtedPositions;

public:

    std::list<Position> getPlayer1Positions() { return player1Pieces; }
    void setPlayer1Positions(std::list<Position> & positions) { player1Pieces = positions; }

    std::list<Position> getPlayer2Positions() { return player2Pieces; }
    void setPlayer2Positions(std::list<Position> & positions) { player2Pieces = positions; }

    void updateBoardStatus(std::list<Position> & possibeMovements);
    void resetBoardStatus();
};


#endif // BOARD_H
