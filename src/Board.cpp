#include "board.h"

Board::Board()
{
    boardStatus.clear();
    player1Pieces.clear();
    player2Pieces.clear();
}

void Board::updateBoardStatus(std::list<Position> & possibeMovements) 
{
    this->resetBoardStatus();

    for (auto &movement : possibeMovements)
    {
        PositionStatus status;
        status.position = movement;
        status.status = Status::HIGHLIGHTED;
        
        this->boardStatus.push_back(status); 
    }

}

std::list<PositionStatus> Board::getBoardStatus ()
{
    return this->boardStatus;
}

void Board::resetBoardStatus() 
{
    this->boardStatus.clear();
}
