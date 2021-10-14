#include "game.h"

Game::Game(IPlayer *player1, IPlayer *player2)
{
    Board board;
    this->board = &board;

    this->player1 = player1;
    this->player2 = player2;

    this->turn = PlayerTurn::TURN_PLAYER1;
    this->updateBoard();
}

IPlayer *Game::getCurrentPlayer() 
{
    return (this->turn == PlayerTurn::TURN_PLAYER1) ? this->player1
                                                    : this->player2; 
}

IPlayer *Game::getOpponentPlayer() 
{
    return (this->turn == PlayerTurn::TURN_PLAYER1) ? this->player2
                                                    : this->player1; 
}

void Game::updateTurn() 
{
    (this->turn == PlayerTurn::TURN_PLAYER1) ? this->turn = PlayerTurn::TURN_PLAYER2
                                             : this->turn = PlayerTurn::TURN_PLAYER1;
}


void Game::updateBoard() 
{
    std::vector<Position> player1, player2;

    player1 = getCurrentPlayer()->getPositions();
    player2 = getOpponentPlayer()->getPositions();

    this->board->setPlayer1Positions(player1);
    this->board->setPlayer2Positions(player2);
}

void Game::firstClick(Position position) 
{
    //Click on empty postion or opponent piece
    if(!getCurrentPlayer()->selectPiece(position))
    {
        board->resetBoardStatus();
    }
    //Click on self piece
    else
    {
        std::vector<Position> opponent_pieces = getOpponentPlayer()->getPositions();
        std::vector<Position> possible_movements;
        
        if(!getCurrentPlayer()->getPossibleMovements(opponent_pieces, possible_movements))
            this->board->resetBoardStatus();

        this->board->updateBoardStatus(possible_movements);
    }
}

void Game::secondClick(Position position) 
{
    std::vector<Position> opponent_pieces = this->getOpponentPlayer()->getPositions();
    
    if(!getCurrentPlayer()->moveSelectedPiece(opponent_pieces, position))
        return;

    if(getCurrentPlayer()->isAttack(position))
        this->getOpponentPlayer()->receiveAttack(position);

    board->resetBoardStatus();
    this->updateBoard();
    this->updateTurn();
}

void Game::selectPosition(Position position) 
{
    //First click (HighLight Positions)
    if(!getCurrentPlayer()->isPieceSelected())
    {
        firstClick(position);
    }
    //Second click (Move Piece or reset)
    else
    {
        secondClick(position);
    }
}
