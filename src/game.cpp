#include "game.h"
#include <iostream>

Game::Game(IPlayer *player1, IPlayer *player2)
{
    this->player1 = player1;
    this->player2 = player2;

    this->turn = PlayerTurn::TURN_PLAYER1;
    this->board = new Board(player1, player2);
    this->status = GameStatus::PLAYING;
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
    std::list<PieceInfo> player1_pieces, player2_pieces;

    player1_pieces = player1->getPiecesInfo();
    player2_pieces = player2->getPiecesInfo();

    this->board->setPlayer1Pieces(player1_pieces);
    this->board->setPlayer2Pieces(player2_pieces);
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
        this->board->updateBoardStatus();

        if(this->getCurrentPlayer()->getInCheck())
        {
            Position king_position = this->getCurrentPlayer()->getKingPosition();
            this->board->addCheckToBoardStatus(king_position);
        }
    }
}

void Game::secondClick(Position position) 
{
    std::list<Piece *> opponent_pieces = this->getOpponentPlayer()->getPieces();
    board->resetBoardStatus();
    
    //The isPossibleMovement function was removed from moveSelected Piece
    //Now, it is possible to move the piece to a prohibited position
    //Will be necessary to add isPossibleMovement function in the board class
    if(!getCurrentPlayer()->moveSelectedPiece(opponent_pieces, position))
        return;

    if(getCurrentPlayer()->isAttack(position))
        this->getOpponentPlayer()->receiveAttack(position);

    this->updateTurn();
    this->updateBoard();
    this->board->setTurn(this->turn);

    //Check if the game is over and set the game Status
    this->setStatus(board->isCheckmate() ? GameStatus::ENDED
                                         : GameStatus::PLAYING);

    if(this->getStatus() == GameStatus::ENDED)
    {
        std::cout << "Checkmate! " << " wins!" << std::endl;
    }
    
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

void Game::resetGame() 
{
    
}

bool Game::isPlayer1Turn() 
{
    return this->turn == PlayerTurn::TURN_PLAYER1;
}

std::list<PositionStatus> Game::getBoardStatus() 
{
    return this->board->getBoardStatus();
}

std::list<PieceInfo> Game::getPlayer1Pieces() 
{
    return this->board->getPlayer1Pieces();
}

std::list<PieceInfo> Game::getPlayer2Pieces() 
{
    return this->board->getPlayer2Pieces();
}

