#include "board.h"
#include "player.h"
#include "boardengine.h"
#include <algorithm>
#include <iostream>

Board::Board(const PlayerManager *players) : players(players)
{
    this->unslect();
}

const Piece* Board::getSeletedPiece() const
{
    return this->selectedPiece;
}

void Board::unslect()
{
    this->selectedPiece = nullptr;
}

bool Board::select(Position &position) 
{
    this->selectedPiece = this->players->getCurrentPlayer()->findPiece(position);
    return isPieceSelected();
}

bool Board::isPieceSelected() const 
{
    return this->selectedPiece != nullptr;
}

bool Board::moveSelectedPiece(Position position)  
{
    //  1. Check if is piece selected
    //  2. If so, get the possible movements 
    //  3. Check if the destination is a possible movement
    //  4. If so, move the piece
    //  5. Check if the movement is an attack
    //  6. If so, capture the opponent piece 

    if(!isPieceSelected())
        return false;

    BoardEngine *boardEngine = new BoardEngine(players);

    std::list<Position> possible_movements = boardEngine->getPossibleMovements(this->selectedPiece);
    bool is_possible_movement = Position::find(possible_movements, position);

    if(!is_possible_movement)
        return false;

    bool success_moved = this->players->getCurrentPlayer()->movePiece(position, this->selectedPiece->getPosition());
    if(!success_moved)
        return false;

    Piece *target_piece = this->players->getOpponentPlayer()->findPiece(position);
    bool is_attack = target_piece != NULL; 

    if(is_attack)
        this->players->getOpponentPlayer()->capturePiece(target_piece->getPosition());

    return true;
}