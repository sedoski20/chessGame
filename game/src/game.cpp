#include "game.h"
#include <iostream>
#include "board.h"

Game::Game()
{
    this->board = new Board();
    this->status = GameStatus::PLAYING;
    this->updateBoard();
}

void Game::updateBoard() 
{
    this->boardStatus.addPiecesInfo(this->board->getPlayer1()->getPieces(),
                                    this->board->getPlayer2()->getPieces());
}

void Game::firstClick(Position position) 
{
    boardStatus.reset();
    bool isPieceSeleceted = board->select(position);

    if(!isPieceSeleceted)
        return;

    boardStatus.addPossibleMovements(board->getPossibleMovements(), board->getBoardPositions());
    boardStatus.addSelectedPiece(position);

    if(board->isCheckArrangement(board->getBoardPositions()));
        boardStatus.addCheck(Position(0,0)); //TODO: find a way to get the king position
}

void Game::secondClick(Position position) 
{
    boardStatus.reset();

    if(!board->moveSelectedPiece(position))
    {
        this->board->unslect();
        return;
    }

    //Check if the game is over and set the game Status
    this->status = (board->isCheckmate() ? GameStatus::ENDED
                                         : GameStatus::PLAYING);

    this->updateBoard();
}

void Game::selectPosition(Position position) 
{
    if(board->isPieceSelected())
        firstClick(position);
    else
        secondClick(position);
}



