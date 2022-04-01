#include "boardstatus.h"
#include <algorithm>

BoardStatus::BoardStatus(const PlayerManager *players) : players(players)
{ 
    this->boardEngine = new BoardEngine(players);
    this->reset();
}

void BoardStatus::reset() 
{
    this->boardStatus.clear();
}

void BoardStatus::addPossibleMovements(const Piece * selectedPiece) 
{
    std::list<Position> possible_movements = this->boardEngine->getPossibleMovements(selectedPiece);

    //Add Highlighted and attack positions to the board status
    for (auto &movement : possible_movements)
    {
        Status status = (this->boardEngine->isAttack(movement)) ? Status::ATTACK
                                                                : Status::HIGHLIGHTED;

            this->boardStatus.push_back(PositionStatus(movement, status)); 
    }
}

void BoardStatus::addCheck()  
{
    Position king_position = this->players->getCurrentPlayer()->getKingPosition();

    if(this->boardEngine->isCheck())
        this->boardStatus.push_back(PositionStatus(king_position, Status::CHECK)); 
}

void BoardStatus::addSelectedPiece(const Piece * selectedPiece) 
{
    this->boardStatus.push_back(PositionStatus(selectedPiece->getPosition(), Status::SELECTED));
}

std::list<PositionStatus> BoardStatus::getHighlightedPositions() const 
{
    return this->boardStatus;
}

std::list<const Piece*> BoardStatus::getPlayer1Pieces() const 
{
    return this->players->getPlayer1()->getPieces();
}

std::list<const Piece*> BoardStatus::getPlayer2Pieces() const 
{
    return this->players->getPlayer2()->getPieces();
}

void BoardStatus::update(const Piece *selectedPiece)
{
    this->reset();

    if(!selectedPiece)
        return;

    this->addPossibleMovements(selectedPiece);
    this->addSelectedPiece(selectedPiece);
    this->addCheck();
}
