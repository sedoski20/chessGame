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
    std::vector<Position> player1Pieces;
    std::vector<Position> player2Pieces;
    std::vector<PositionStatus> highlihtedPositions;

public:
    
    std::vector<Position> getPlayer1Positions() { return player1Pieces; }
    void setPlayer1Positions(std::vector<Position> & positions) { player1Pieces = positions; }

    std::vector<Position> getPlayer2Positions() { return player2Pieces; }
    void setPlayer2Positions(std::vector<Position> & positions) { player2Pieces = positions; }

    void updateBoardStatus(std::vector<Position> & possibeMovements);
    void resetBoardStatus();
};


#endif // BOARD_H
