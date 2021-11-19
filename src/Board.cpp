#include "board.h"
#include <algorithm>

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
    std::list<Position> possible_movements = selectedPiece->getPossibleMovements(this->getCurrentPlayer()->getPositions(), this->getOpponentPlayer()->getPositions());

    // removeUnsafeMovements(possibleMovements, opponentPieces, selectedPiece);
    return possible_movements;   
}
