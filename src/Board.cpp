#include "board.h"
#include <algorithm>

Board::Board()
{
    boardStatus.clear();
    player1Pieces.clear();
    player2Pieces.clear();
}

void Board::updateBoardStatus(std::list<Position> & possibeMovements, std::list<Position> & opponnentPositions) 
{
    this->resetBoardStatus();
    std::list<Position>::iterator iterator;

    for (auto &movement : possibeMovements)
    {
        PositionStatus status;
        status.position = movement;
        
        //Check if some opponent piece is one possible movement, if so, mark it as an attack
        iterator = std::find(opponnentPositions.begin(), opponnentPositions.end(), movement);

        if(iterator == std::end(opponnentPositions))
            status.status = Status::HIGHLIGHTED;
        else
            status.status = Status::ATTACK;
        
        this->boardStatus.push_back(status); 
    }

}

void Board::addCheckToBaordStatus(Position & position) 
{
    PositionStatus status;
    status.position = position;
    status.status = Status::ATTACK;

    this->boardStatus.push_back(status);
}

std::list<PositionStatus> Board::getBoardStatus ()
{
    return this->boardStatus;
}

void Board::resetBoardStatus() 
{
    this->boardStatus.clear();
}
