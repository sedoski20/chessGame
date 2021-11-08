#include "player.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include <algorithm>

Player::Player(MovementDirection direction)
{
    this->name = "";
    this->pieces.clear();
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
    this->selectedPiece = NULL;
}

Player::Player(MovementDirection direction, std::string playerName) : Player::Player(direction)
{
    this->name = playerName;
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

bool Player::findPiece(Position location, Piece *&piece) 
{
    for(Piece * temp_piece : pieces)
    {
        if(temp_piece->getCurrentPosition() == location)
        {
            piece = temp_piece;
            return true;
        }
    }

    return false;
}

bool Player::isPieceSelected() 
{
    if(selectedPiece == NULL)
        return false;

    return true;
}

std::list<Position> Player::getPositions() 
{
    std::list<Position> positions;
    for(Piece * piece : pieces)
        positions.push_back(piece->getCurrentPosition());

    return positions;
}

std::list<PieceInfo> Player::getPiecesInfo() 
{
    std::list<PieceInfo> piecesInfo;
    
    for(Piece * piece : pieces)
    {   
        PieceInfo pieceInfo;
        pieceInfo.position = piece->getCurrentPosition();
        pieceInfo.type = piece->getType();

        piecesInfo.push_back(pieceInfo);
    }    
        
    return piecesInfo;
}

bool Player::selectPiece(Position position)
{
    selectedPiece = NULL;

    //If there is no piece on position, return false
    if(!findPiece(position, selectedPiece))
        return false;

    return true;
}

bool Player::moveSelectedPiece(std::list<Position> &opponentPositions, Position destination) 
{
    if(!isPieceSelected())
    {
        return false;
    }

    if(destination == selectedPiece->getCurrentPosition())
    {
        selectedPiece = NULL;
        return false;
    }


    if(!isPossibleMovement(opponentPositions, destination))
    {
        selectedPiece = NULL;
        return false;
    }

    if(!selectedPiece->move(destination))
    {
        selectedPiece = NULL;
        return false;
    }

    selectedPiece = NULL;
    return true;   
}

void Player::updateScore() 
{
    //TODO: implement
}

bool Player::receiveAttack(Position position) 
{
   for(Piece * piece : pieces)
   {
       if(piece->getCurrentPosition() == position)
       {
            pieces.remove(piece);
            return true;
       }
   }

   return false;
}

bool Player::isAttack(Position position) 
{
    std::list<Position>::iterator iterator;   

    iterator = std::find(this->getPositions().begin(), this->getPositions().end(), position);
    bool result = (iterator != std::end(this->getPositions()));

    return result;
}

std::list<Piece *> Player::getPieces() const
{
    return this->pieces;
}

bool Player::getPossibleMovements(std::list<Position> &opponentPositions, std::list<Position> &possibleMovements) 
{
    if(!isPieceSelected())
        return false;

    Piece *piece = selectedPiece;

    switch (piece->getType())
    {
        case PieceType::PAWN:
        {
            Pawn *pawn = dynamic_cast<Pawn*> (piece);
            possibleMovements = pawn->getPossibleMovements(this->getPositions(), opponentPositions);
            break;
        } 

        case PieceType::BISHOP: 
        {
            Bishop *bishop = dynamic_cast<Bishop*> (piece);
            possibleMovements = bishop->getPossibleMovements(this->getPositions(), opponentPositions);
            break;
        }

        case PieceType::KNIGHT: 
        {
            Knight *knight = dynamic_cast<Knight*> (piece);
            possibleMovements = knight->getPossibleMovements(this->getPositions(), opponentPositions);
            break;
        }

        case PieceType::ROOK: 
        {
            Rook *rook = dynamic_cast<Rook*> (piece);
            possibleMovements = rook->getPossibleMovements(this->getPositions(), opponentPositions);
            break; 
        }

        case PieceType::QUEEN: 
        {
            Queen *queen = dynamic_cast<Queen*> (piece);
            possibleMovements = queen->getPossibleMovements(this->getPositions(), opponentPositions);
            break; 
        }

        case PieceType::KING: 
        {
            King *king = dynamic_cast<King*> (piece);
            possibleMovements = king->getPossibleMovements(this->getPositions(), opponentPositions);
            break; 
        }

        default:
            return false;
    }

    possibleMovements.push_back(piece->getCurrentPosition());
    return true;
}

bool Player::isPossibleMovement(std::list<Position> &opponentPositions, Position destination) 
{
    std::list<Position> possible_movements;
    
    if(!this->getPossibleMovements(opponentPositions, possible_movements))
        return false;

    for(Position pos : possible_movements)
        if(pos == destination)
            return true;

    return false;
}
