#include "player.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include <algorithm>
#include <iostream>

Player::Player(MovementDirection direction)
{
    this->pieces.clear();
    int first_row = (direction == MovementDirection::MOVING_UP) ? 0 : 7;
    int second_row = (direction == MovementDirection::MOVING_UP) ? 1 : 6;

    createRooks(first_row);
    createKnights(first_row);
    createBishops(first_row);
    createQueen(first_row);
    createKing(first_row);
    createPawns(second_row);
}

Player::~Player()
{
    for(auto piece : this->pieces)
        delete piece;
        
    this->pieces.clear();
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
    int column = 3;
    Queen *queen = new Queen(Position(referenceRow, column));
    this->pieces.push_back(queen);
}

void Player::createKing(int referenceRow) 
{
    int column = 4;
    King *king = new King(Position(referenceRow, column));
    this->pieces.push_back(king);
}

Piece* Player:: findPiece(Position location) const 
{
    for(auto piece : this->pieces)
        if(piece->getPosition() == location)
            return piece;

    return NULL;
}

bool Player::movePiece(Position destination, Position from) 
{
    Piece *piece = this->findPiece(from);

    if(piece == NULL)
        return false;

    if(!piece->move(destination))
        return false;

    return true;   
}

bool Player::capturePiece(Position target) 
{
    Piece * piece = Piece::find(this->pieces, target);
    if(piece == NULL)
        return false;

    this->pieces.remove(piece);
    
    delete piece;
    return true;
}

const std::list<const Piece *> Player::getPieces() const
{
    std::list<const Piece *> const_pieces;

    for(const Piece * piece : this->pieces)
        const_pieces.push_back(piece);

    return const_pieces;
}

Position Player::getKingPosition() const
{
    for(const Piece * piece : this->pieces)
        if(piece->getType() == PieceType::KING)
            return piece->getPosition();

    return Position(0, 0);
}
