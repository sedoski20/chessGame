#include "player.h"
#include "pawn.h"

Player::Player(movementDirection direction, std::string playerName) 
{
    this->pieces.clear();
    this->name = playerName;

    int first_row = 0;
    int second_row = 1;

    if(direction == movementDirection::MOVING_UP)
    {
        first_row = 7;
        second_row = 6;
    }

    createPawns(second_row);
    this->activePieces = this->pieces.size();
}

void Player::createPawns(int referenceRow) 
{
    for(int i = 0; i < 7; i++)
    {
        Position position (referenceRow, i);
        Pawn * pawn = new Pawn(position);
        this->pieces.push_back(pawn);
    }
}

void Player::createRooks(int referenceRow) 
{
    
}

void Player::createKnights(int referenceRow) 
{
    
}

void Player::createBishops(int referenceRow) 
{
    
}

void Player::createQueen(int referenceRow) 
{
    
}

void Player::createKing(int referenceRow) 
{
    
}

bool Player::selectPiece(Position position)
{
    
}

bool Player::movePiece(Position position) 
{
    
}

void Player::updateScore() 
{
    
}
