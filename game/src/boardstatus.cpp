#include "boardstatus.h"
#include <algorithm>

BoardStatus::BoardStatus(const PlayerManager *players) : players(players)
{ 
    this->reset();
}

void BoardStatus::reset() 
{
    this->boardStatus.clear();
}

void BoardStatus::addPossibleMovements(const Piece * selectedPiece) 
{
    BoardEngine board_engine(players);
    std::list<Position> possible_movements = board_engine.getPossibleMovements(selectedPiece);

    //Add Highlighted and attack positions to the board status
    for (auto &movement : possible_movements)
    {
        Status status = (board_engine.isAttack(movement)) ? Status::ATTACK
                                                                : Status::HIGHLIGHTED;

            this->boardStatus.push_back(PositionStatus(movement, status)); 
    }
}

void BoardStatus::addCheck()  
{
    Position king_position = this->players->getCurrentPlayer()->getKingPosition();
    BoardEngine board_engine(players);

    if(!board_engine.isCheck())
        return;

    Piece *selected_piece = this->players->getCurrentPlayer()->findPiece(king_position);
    bool is_king_selected =  selected_piece->getType() == PieceType::KING;
    
    if(is_king_selected)
        this->boardStatus.remove(PositionStatus(king_position, Status::SELECTED));
        
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
