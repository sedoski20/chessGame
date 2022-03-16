#include "board.h"
#include <algorithm>
#include <iostream>
#include "player.h"

Board::Board()
{
    this->player1 = new Player(MovementDirection::MOVING_UP);
    this->player2 = new Player(MovementDirection::MOVING_DOWN);
}

// void Board::updateBoardStatus() 
// {
//     this->resetBoardStatus();
//     std::list<Position>::iterator iterator;

//     std::list<Position> possible_movements = this->getPossibleMovements();

//     //Add seleceted piece position to board status
//     possible_movements.push_back(this->getCurrentPlayer()->getSelectedPiece()->getCurrentPosition());

//     std::list<Position> opponent_postions = this->getOpponentPlayer()->getPositions();

//     if(isSafeArrangement(getCurrentPlayer()->getPositions(), getOpponentPlayer()->getPieces(), getCurrentPlayer()->getKingPosition()))
//         getCurrentPlayer()->setInCheck(true);
//     else
//         getCurrentPlayer()->setInCheck(false);

//     for (auto &movement : possible_movements)
//     {
//         PositionStatus status;
//         status.position = movement;
        
//         //Check if some opponent piece is one possible movement, if so, mark it as an attack
//         iterator = std::find(opponent_postions.begin(), opponent_postions.end(), movement);

//         if(iterator == std::end(opponent_postions))
//             status.status = Status::HIGHLIGHTED;
//         else
//             status.status = Status::ATTACK;
        
//         this->boardStatus.push_back(status); 
//     }
// }

// void Board::addCheckToBoardStatus(Position & position) 
// {
//     PositionStatus status;
//     status.position = position;
//     status.status = Status::ATTACK;

//     this->boardStatus.push_back(status);
// }

// std::list<PositionStatus> Board::getBoardStatus ()
// {
//     return this->boardStatus;
// }


// bool Board::isPossibleMovement(Position &destination) 
// {
//     std::list<Position> possible_movements;

//     possible_movements =  this->getPossibleMovements();

//     for(Position pos : possible_movements)
//         if(pos == destination)
//             return true;

//     return false;
// }

IPlayer *Board::getCurrentPlayer() const
{
    return (this->turn == PlayerTurn::TURN_PLAYER1) ? this->player1
                                                    : this->player2; 
}

IPlayer *Board::getOpponentPlayer() const
{
    return (this->turn == PlayerTurn::TURN_PLAYER1) ? this->player2
                                                    : this->player1; 
}

BoardPositions Board::getBoardPositions() const 
{
    std::list<Position> current_positions, opponent_positions;

    for(Piece * p : this->getCurrentPlayer()->getPieces())
        current_positions.push_back(p->getCurrentPosition());

    for(Piece * p : this->getOpponentPlayer()->getPieces())
        opponent_positions.push_back(p->getCurrentPosition());

    return BoardPositions(current_positions, opponent_positions);
}

void Board::updateTurn()
{
    (this->turn == PlayerTurn::TURN_PLAYER1) ? this->turn = PlayerTurn::TURN_PLAYER2
                                             : this->turn = PlayerTurn::TURN_PLAYER1;
}

void Board::unslect()
{
    this->selectedPiece = NULL;
}

bool Board::select(Position &position) 
{
    this->selectedPiece = this->getCurrentPlayer()->findPiece(position);
    const Piece* test = this->getCurrentPlayer()->findPiece(position);
    return isPieceSelected();
}

bool Board::isPieceSelected() const 
{
    return this->selectedPiece != NULL;
}

bool Board::moveSelectedPiece(Position position)  
{
    //  1. Check if is piece selected
    //  2. If so, get the possible movements 
    //  3. Check if the destination is a possible movement
    //  4. If so, move the piece
    //  5. Check if the movement is an attack
    //  6. If so, capture the opponent piece 

    if(!isPieceSelected())
        return false;

    std::list<Position> possible_movements = this->getPossibleMovements();

    bool is_possible_movement = Position::find(possible_movements, position);

    if(!is_possible_movement)
        return false;

    if(this->getCurrentPlayer()->movePiece(position, this->selectedPiece))
        return false;

    Piece *target_piece = this->getOpponentPlayer()->findPiece(position);
    bool is_attack = target_piece != NULL; 

    if(is_attack)
        this->getOpponentPlayer()->capturePiece(target_piece);

    return true;
}

std::list<Position> Board::getPossibleMovements() 
{
    //  1. Check if is piece selected
    //  2. If so, get the possible movements calling the piece method
    //  3. Remove the movements that where the kink is in check
    //  4. Return the list of possible movements

    std::list<Position> possible_movements;
    possible_movements.clear();
    
    if(!this->isPieceSelected())
        return possible_movements;

    possible_movements = selectedPiece->getPossibleMovements(this->getBoardPositions());
    removeUnsafeMovements(possible_movements);

    return possible_movements;   

}

void Board::removeUnsafeMovements(std::list<Position> &movements) const
{
    // For each movement:
    //  1. Get new arrangement from the movement
    //  2. Check if it is a safe arrangement
    //  3. If not, remove the movement from possible movements 

    for(Position mevement : movements)
    {
        BoardPositions new_arrangement = this->getNewArrangementFromMovement(mevement);

        if(isCheckArrangement(new_arrangement))
            movements.remove(mevement);
    }
}

BoardPositions Board::getNewArrangementFromMovement(Position movement) const 
{
    //  1. Get the current board positions
    //  2. Remove the selected piece position from the new current player positions
    //  3. Add the new position of the selected piece to the current player positions
    //  4. Get the opponent positions
    //  5. If the movement is an attack, remove the opponent player positions
    //  6. Return the new arragement

    BoardPositions board_positions = this->getBoardPositions();

    std::list<Position> current_player_new_positions = board_positions.getCurrentPlayerPositions();
    current_player_new_positions.remove(selectedPiece->getCurrentPosition());
    current_player_new_positions.push_back(movement);

    std::list<Position> opponent_player_new_positions= board_positions.getOpponentPlayerPositions();
    bool is_attack = Position::find(opponent_player_new_positions, movement);

    if(is_attack)
        opponent_player_new_positions.remove(movement); 
    
    return BoardPositions(current_player_new_positions, opponent_player_new_positions);
}

bool Board::isCheckArrangement(const BoardPositions arrangement) const 
{
    //  1. For each opponent position of the new arrangement:
    //  2. Get the corresponding piece (if it not found, return false)
    //  3. Get the possible movements for the piece
    //  4. Check if the king position is in the possible movements
    //  5. If so, return false
    //  6. If all positions is already checked, return true

    for(const Position position : arrangement.getOpponentPlayerPositions())
    {
        Piece * opponent_piece = Piece::find(this->getOpponentPlayer()->getPieces(), position); 

        if(opponent_piece == NULL)
        {
            std::cout << "Error: The new arragement has one position that is not on the opponent player pieces!" << std::endl; 
            return false;
        }

        std::list<Position> possible_movements = opponent_piece->getPossibleMovements(arrangement);
        bool is_check = Position::find(possible_movements, this->getCurrentPlayer()->getKingPosition()); 
        
        if(is_check)
            return true;
    }

    return false;
}

bool Board::isCheckmate() const
{
    //  1. For each current player piece:
    //  2. Get the possible movements
    //  3. Remove unsafe movements
    //  4. If all movements were removed, return false
    //  5. If all pieces is already checked, return true

    BoardPositions board = this->getBoardPositions(); 
    std::list<Position> possible_movements;

    for(const Piece * piece : this->getCurrentPlayer()->getPieces())
    {
        possible_movements = piece->getPossibleMovements(board);
        removeUnsafeMovements(possible_movements);

        if(possible_movements.size() > 0)
            return false;
    }

    return true;
}
