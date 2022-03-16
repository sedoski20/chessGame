#include "boardstatus.h"
#include <algorithm>

BoardStatus::BoardStatus(){ this->boardStatus.clear(); }

void BoardStatus::addPossibleMovements(const std::list<Position> &possibleMovements, const BoardPositions &board) 
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

void BoardStatus::addPiecesInfo(const std::list<Piece *> player1Pieces, const std::list<Piece *> player2Pieces) 
{
    this->player1PiecesInfo.clear();

    for(Piece * piece : player1Pieces)
    {
        PieceInfo info;
        info.position = piece->getCurrentPosition();
        info.type = piece->getType();
        player1PiecesInfo.push_back(info);
    }

    this->player2PiecesInfo.clear();

    for(Piece * piece : player2Pieces)
    {
        PieceInfo info;
        info.position = piece->getCurrentPosition();
        info.type = piece->getType();
        player2PiecesInfo.push_back(info);
    }
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

std::list<PositionStatus> BoardStatus::getBoardStatus() const 
{
    return this->boardStatus;
}

std::list<PieceInfo> BoardStatus::getPlayer1PiecesInfo() const 
{
    return this->player1PiecesInfo;
}

std::list<PieceInfo> BoardStatus::getPlayer2PiecesInfo() const 
{
    return this->player2PiecesInfo;
}
