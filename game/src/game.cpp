#include <iostream>
#include "game.h"
#include "board.h"
#include "playermanager.h"
#include "player.h"


Game::Game()
{
    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_DOWN);
    
    this->turn = PlayerTurn::TURN_PLAYER1;
    this->players = new PlayerManager(player1, player2, &turn);
    this->board = new Board(players);
}

void Game::updateTurn() 
{
    (this->turn == PlayerTurn::TURN_PLAYER1) ? this->turn = PlayerTurn::TURN_PLAYER2
                                             : this->turn = PlayerTurn::TURN_PLAYER1;
}

bool Game::firstClick(Position position) const
{
    return board->select(position);
}

bool Game::secondClick(Position position) const
{
    bool success = board->moveSelectedPiece(position);
    this->board->unslect();
    return success;
}

void Game::selectPosition(Position position)
{
    if(!board->isPieceSelected())
        firstClick(position);
    else
    {
        if(secondClick(position))
            this->updateTurn();
    }
}

const BoardStatus Game::getBoardStatus() const 
{
    BoardStatus board_status(players);
    board_status.update(this->board->getSeletedPiece());

    return board_status;
}

const GameStatus Game::getGameStatus() const
{
    BoardEngine board_engine(players);
    GameStatus status = (board_engine.isCheckMate()) ? GameStatus::ENDED
                                                     : GameStatus::PLAYING;

    return status;
}



