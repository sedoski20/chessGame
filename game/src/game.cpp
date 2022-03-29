#include "game.h"
#include <iostream>
#include "board.h"
#include "playermanager.h"
#include "player.h"

Game::Game()
{
    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_DOWN);
    PlayerManager *players = new PlayerManager(player1, player2);

    this->board = new Board(players);
    this->status = GameStatus::PLAYING;
}

void Game::firstClick(Position position) 
{
    board->select(position);
}

void Game::secondClick(Position position) 
{
    bool success = board->moveSelectedPiece(position);

    this->board->unslect();
    
    if(!success)
        return;
        
    // this->board->updateTurn();

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



