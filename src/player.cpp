#include "player.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

Player::Player(MovementDirection direction, std::string playerName) 
{
    this->pieces.clear();
    this->name = playerName;

    int first_row = 0;
    int second_row = 1;

    if(direction == MovementDirection::MOVING_DOWN)
    {
        first_row = 7;
        second_row = 6;
    }

    createRooks(first_row);
    createKnights(first_row);
    createBishops(first_row);
    createQueen(first_row);
    createKing(first_row);
    createPawns(second_row);

    this->activePieces = this->pieces.size();
}

void Player::createPawns(int referenceRow) 
{
    for(int i = 0; i < 8; i++)
    {
        Position position (referenceRow, i);
        Pawn * pawn = new Pawn(position);
        this->pieces.push_back(pawn);
    }
}

void Player::createRooks(int referenceRow) 
{
    Rook *rook1, *rook2;
    rook1 = new Rook(Position(referenceRow, 0));
    rook2 = new Rook(Position(referenceRow, 7));
    this->pieces.push_back(rook1);
    this->pieces.push_back(rook2);
}

void Player::createKnights(int referenceRow) 
{
    Knight *knight1, *knight2;
    knight1 = new Knight(Position(referenceRow, 1));
    knight2 = new Knight(Position(referenceRow, 6));
    this->pieces.push_back(knight1);
    this->pieces.push_back(knight2);
}

void Player::createBishops(int referenceRow) 
{
    Bishop *bishop1, *bishop2;
    bishop1 = new Bishop(Position(referenceRow, 2));
    bishop2 = new Bishop(Position(referenceRow, 5));
    this->pieces.push_back(bishop1);
    this->pieces.push_back(bishop2);   
}

void Player::createQueen(int referenceRow) 
{
    int column;
    if(referenceRow == 0) column = 4; else column = 3;
    Queen *queen = new Queen(Position(referenceRow, column));
    this->pieces.push_back(queen);
}

void Player::createKing(int referenceRow) 
{
    int column;
    if(referenceRow == 0) column = 3; else column = 4;
    King *king = new King(Position(referenceRow, column));
    this->pieces.push_back(king);
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

std::vector<Piece *> Player::getPieces() const
{
    return this->pieces;
}
