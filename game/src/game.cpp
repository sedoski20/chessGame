#include <iostream>
#include "game.h"
#include "board.h"
#include "player.h"
#include "boardengine.h"
#include "boardstatus.h"


Game::Game()
{
    IPlayer *player1 = new Player(MovementDirection::MOVING_UP);
    IPlayer *player2 = new Player(MovementDirection::MOVING_DOWN);
    
    this->turn = PlayerTurn::TURN_PLAYER1;
    this->players = new PlayerManager(player1, player2, &turn);
    this->board = new Board(players);
}

Game::Game(IBoard *board, PlayerManager *players) : board(board), players(players)
{
    this->turn = PlayerTurn::TURN_PLAYER1;
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

const std::list<PositionStatus> Game::getHighlightedPositions() const
{
    BoardStatus board_status(players);
    board_status.update(this->board->getSelectedPiece());

    return board_status.getHighlightedPositions();
}

const std::list<PieceInfo> Game::getPlayer1Pieces() const
{
    BoardStatus board_status(players);
    board_status.update(this->board->getSelectedPiece());

    return board_status.getPlayer1Pieces();   
}

const std::list<PieceInfo> Game::getPlayer2Pieces() const
{
    BoardStatus board_status(players);
    board_status.update(this->board->getSelectedPiece());

    return board_status.getPlayer2Pieces();   
}

const GameStatus Game::getGameStatus() const
{
    BoardEngine board_engine(players);
    GameStatus status = (board_engine.isCheckMate()) ? GameStatus::ENDED
                                                     : GameStatus::PLAYING;

    return status;
}



