#include "boardstatus.h"
#include <algorithm>

BoardStatus::BoardStatus(){ this->boardStatus.clear(); }

void BoardStatus::addPossibleMovements(std::list<Position> &possibleMovements, const BoardPositions &board) 
{
    this->reset();
    //Add Highlighted and attack positions to the board status
    for (auto &movement : possibleMovements)
    {
        bool isAttack = Position::find(board.getOpponentPlayerPositions(), movement);

        if(isAttack)
            this->boardStatus.push_back(PositionStatus(movement, Status::ATTACK)); 
        else
            this->boardStatus.push_back(PositionStatus(movement, Status::HIGHLIGHTED)); 
    }
}

void BoardStatus::reset() 
{
    this->boardStatus.clear();
}

void BoardStatus::addCheck(Position kingPosition)  
{
    this->boardStatus.push_back(PositionStatus(kingPosition, Status::CHECK)); 
}

void BoardStatus::addSelectedPiece(Position selectedPiece) 
{
    this->boardStatus.push_back(PositionStatus(selectedPiece, Status::SELECTED));
}

Status BoardStatus::getStatus(Position position) const 
{
	for(PositionStatus status : this->boardStatus)
        if(status.getPosition() == position)
            return status.getStatus();

    return Status::NORMAL;
}





    
