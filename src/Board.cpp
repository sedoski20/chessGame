#include "board.h"
#include <algorithm>
#include <iostream>

Board::Board(IPlayer *player1, IPlayer *player2)
{
    this->player1 = player1;
    this->player2 = player2;
    boardStatus.clear();
    player1Pieces.clear();
    player2Pieces.clear();
}

void Board::updateBoardStatus(PlayerTurn currentTurn) 
{
    this->resetBoardStatus();
    this->turn = currentTurn;
    std::list<Position>::iterator iterator;

    std::list<Position> possible_movements = this->getPossibleMovementsForSelectedPiece();

    //Add seleceted piece position to board status
    possible_movements.push_back(this->getCurrentPlayer()->getSelectedPiece()->getCurrentPosition());

    std::list<Position> opponent_postions = this->getOpponentPlayer()->getPositions();

    for (auto &movement : possible_movements)
    {
        PositionStatus status;
        status.position = movement;
        
        //Check if some opponent piece is one possible movement, if so, mark it as an attack
        iterator = std::find(opponent_postions.begin(), opponent_postions.end(), movement);

        if(iterator == std::end(opponent_postions))
            status.status = Status::HIGHLIGHTED;
        else
            status.status = Status::ATTACK;
        
        this->boardStatus.push_back(status); 
    }

    isCheckmate();

}

void Board::addCheckToBoardStatus(Position & position) 
{
    PositionStatus status;
    status.position = position;
    status.status = Status::ATTACK;

    this->boardStatus.push_back(status);
}

std::list<PositionStatus> Board::getBoardStatus ()
{
    return this->boardStatus;
}

void Board::resetBoardStatus() 
{
    this->boardStatus.clear();
}

IPlayer *Board::getCurrentPlayer() 
{
    return (this->turn == PlayerTurn::TURN_PLAYER1) ? this->player1
                                                    : this->player2; 
}

IPlayer *Board::getOpponentPlayer() 
{
    return (this->turn == PlayerTurn::TURN_PLAYER1) ? this->player2
                                                    : this->player1; 
}

std::list<Position> Board::getPossibleMovementsForSelectedPiece() 
{
    // if(!isPieceSelected())
    //     return false;

    // //Update check status
    // if(isCheckFromOpponent(this->getPositions(), opponentPieces, this->getKingPosition()))
    //     this->inCheck = true;
    // else
    //     this->inCheck = false;

    // std::list<Position> opponent_positions;

    // for(Piece * piece : opponentPieces)
    //     opponent_positions.push_back(piece->getCurrentPosition());

    Piece *selectedPiece = getCurrentPlayer()->getSelectedPiece();
    std::list<Position> current_player_positions = getCurrentPlayer()->getPositions();
    std::list<Position> opponent_positions = getOpponentPlayer()->getPositions();

    std::list<Position> possible_movements = selectedPiece->getPossibleMovements(current_player_positions, opponent_positions);
    removeUnsafeMovements(possible_movements, selectedPiece);
    return possible_movements;   
}

void Board::removeUnsafeMovements(std::list<Position> &movements, Piece *selectedPiece) 
{
    Position kingPosition;

    for(Position pos : movements)
    {
        std::list<Position> possible_self_positions = this->getCurrentPlayer()->getPositions();
        std::list<Piece *> current_opponent_pieces =this->getOpponentPlayer()->getPieces();
        std::list<Piece *> possible_opponent_pieces;

        //Append opponent positions
        //Except if the possible movement is an attack
        for(Piece * piece : current_opponent_pieces)
        {
            if(!(piece->getCurrentPosition() == pos))
                possible_opponent_pieces.push_back(piece);
        }

        //Remove the selected piece
        //Append the possible movement (pos) to get a new positions arrangement for the current player
        possible_self_positions.remove(selectedPiece->getCurrentPosition());
        possible_self_positions.push_back(pos);

        if(selectedPiece->getType() == PieceType::KING)
            kingPosition = pos;
        else
            kingPosition = getCurrentPlayer()->getKingPosition();

        //Now we check if this arrangement is safe
        if(isSafeArrangement(possible_self_positions, possible_opponent_pieces, kingPosition))
            movements.remove(pos);
    }
}

bool Board::isSafeArrangement(const std::list<Position> selfPositions, std::list<Piece *> opponentPieces, Position kingPosition) 
{
    //Iterate through all the opponent pieces
    //Get the possible movements for each piece
    //Check if the king is in the possible movements
    //If so, return true

    std::list<Position> opponent_positions;

    for(Piece * piece : opponentPieces)
        opponent_positions.push_back(piece->getCurrentPosition());

    for(Piece * piece : opponentPieces)
    {
        std::list<Position> possible_movements = piece->getPossibleMovements(opponent_positions, selfPositions);

        if(std::find(possible_movements.begin(), possible_movements.end(), kingPosition) != std::end(possible_movements))
            return true;
    }

    return false;
}

bool Board::isCheckmate() 
{
    std::list<Piece *> current_player_pieces = this->getCurrentPlayer()->getPieces();
    std::list<Position> current_player_positions = getCurrentPlayer()->getPositions();
    std::list<Position> current_opponent_positions = getOpponentPlayer()->getPositions();

    std::list<Position> possible_movements;

    for(Piece * piece : current_player_pieces)
    {
        possible_movements = piece->getPossibleMovements(current_player_positions, current_opponent_positions);
        removeUnsafeMovements(possible_movements, piece);

        //TODO: this function is not working properly, maybe the problem is on the removeUnsafeMovements function
        std::cout << "CHECK: Possible movements size - " << possible_movements.size() << std::endl;

        if(possible_movements.size() > 0)
            return false;
    }

    std::cout << "CHECK MATE!" << std::endl;
    return true;
}
