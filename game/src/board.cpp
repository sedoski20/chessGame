#include "board.h"
#include "player.h"
#include "boardengine.h"
#include <algorithm>
#include <iostream>

Board::Board(const PlayerManager *players) : players(players)
{
    this->unselect();
}

Board::~Board() {}

const Piece* Board::getSelectedPiece() const
{
    return this->selectedPiece;
}

void Board::unselect()
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
    //  1. Check if there is no piece already selected
    //  2. If not, get the possible movements 
    //  3. Check if the destination is a possible movement
    //  4. If so, move the piece
    //  5. Check if the movement is an attack
    //  6. If so, capture the opponent piece 

    if(!isPieceSelected())
        return false;

    BoardEngine board_engine(players);

    std::list<Position> possible_movements = board_engine.getPossibleMovements(this->selectedPiece);
    bool is_possible_movement = Position::find(possible_movements, position);

    if(!is_possible_movement)
    {
        this->unselect();
        return false;
    }

    bool success_moved = this->players->getCurrentPlayer()->movePiece(position, this->selectedPiece->getPosition());
    if(!success_moved)
    {
        this->unselect();
        return false;
    }

    bool is_attack = board_engine.isAttack(position); 
    if(is_attack)
        this->players->getOpponentPlayer()->capturePiece(position);

    this->unselect();
    return true;
}