#include "game.h"
#include <iostream>
#include "board.h"

Game::Game()
{
    this->board = new Board();
    this->status = GameStatus::PLAYING;
    this->board->updateBoardStatus();
}

void Game::firstClick(Position position) 
{
    board->select(position);
    this->board->updateBoardStatus();
}

void Game::secondClick(Position position) 
{
    bool success = board->moveSelectedPiece(position);

    this->board->unslect();
    this->board->updateBoardStatus();
    
    if(!success)
        return;
        
    this->board->updateTurn();

    //After a movement the next player can be in a check mate, so
    //Check if the game is over and set the game Status
    this->status = (board->isCheckmate() ? GameStatus::ENDED
                                         : GameStatus::PLAYING);
}

void Game::selectPosition(Position position) 
{
    if(!board->isPieceSelected())
        firstClick(position);
    else
        secondClick(position);
}



