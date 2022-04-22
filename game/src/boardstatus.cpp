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

    if(!this->boardEngine->isCheck())
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

std::list<PieceInfo> BoardStatus::getPlayer1Pieces() const 
{
    std::list<PieceInfo> pieces;

    for(auto piece : this->players->getPlayer1()->getPieces())
        pieces.push_back(PieceInfo(piece->getPosition(), piece->getType()));

    return pieces;
}

std::list<PieceInfo> BoardStatus::getPlayer2Pieces() const 
{
    std::list<PieceInfo> pieces;

    for(auto piece : this->players->getPlayer2()->getPieces())
        pieces.push_back(PieceInfo(piece->getPosition(), piece->getType()));

    return pieces;
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
