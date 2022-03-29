#include "board.h"
#include <algorithm>
#include <iostream>
#include "player.h"

Board::Board(PlayerManager *players)
{
    this->players = players;
    this->turn = PlayerTurn::TURN_PLAYER1;
    this->unslect();
}

const BoardStatus Board::getBoardStatus()
{
    this->boardStatus.reset();
    this->boardStatus.addPiecesInfo(this->players->getPlayer1()->getPieces(),
                                    this->players->getPlayer2()->getPieces());

    if(!this->isPieceSelected())
        return this->boardStatus;

    boardStatus.addPossibleMovements(this->getPossibleMovements(this->selectedPiece), this->getBoardPositions());
    boardStatus.addSelectedPiece(selectedPiece->getPosition());

    if(this->isCheckArrangement(this->getBoardPositions(), this->players->getCurrentPlayer()->getKingPosition()))
        this->boardStatus.addCheck(this->players->getCurrentPlayer()->getKingPosition()); 

    return this->boardStatus;
}

void Board::updateTurn()
{
    (this->turn == PlayerTurn::TURN_PLAYER1) ? this->turn = PlayerTurn::TURN_PLAYER2
                                             : this->turn = PlayerTurn::TURN_PLAYER1;
}

BoardPositions Board::getBoardPositions() const 
{
    std::list<Position> current_positions, opponent_positions;

    for(const Piece * p : this->players->getCurrentPlayer()->getPieces())
        current_positions.push_back(p->getPosition());

    for(const Piece * p : this->players->getOpponentPlayer()->getPieces())
        opponent_positions.push_back(p->getPosition());

    return BoardPositions(current_positions, opponent_positions);
}

void Board::unslect()
{
    this->selectedPiece = nullptr;
}

bool Board::select(Position &position) 
{
    this->selectedPiece = this->players->getCurrentPlayer()->findPiece(position);
    return isPieceSelected();
}

bool Board::isPieceSelected() const 
{
    return this->selectedPiece != nullptr;
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


    std::list<Position> possible_movements = this->getPossibleMovements(this->selectedPiece);
    bool is_possible_movement = Position::find(possible_movements, position);

    if(!is_possible_movement)
        return false;

    bool success_moved = this->players->getCurrentPlayer()->movePiece(position, this->selectedPiece->getPosition());
    if(!success_moved)
        return false;

    Piece *target_piece = this->players->getOpponentPlayer()->findPiece(position);
    bool is_attack = target_piece != NULL; 

    if(is_attack)
        this->players->getOpponentPlayer()->capturePiece(target_piece->getPosition());

    return true;
}

std::list<Position> Board::getPossibleMovements(const Piece *piece) 
{
    //  1. Get the possible movements calling the piece method
    //  3. Remove the movements which the kink is in check
    //  4. Return the list of possible movements

    std::list<Position> possible_movements;
    possible_movements.clear();

    possible_movements = piece->getPossibleMovements(this->getBoardPositions());
    removeUnsafeMovements(possible_movements, piece);

    return possible_movements;   

}

void Board::removeUnsafeMovements(std::list<Position> &movements, const Piece* targetPiece) const
{
    // For each movement:
    //  1. Get new arrangement from the movement
    //  2. Check if it is a safe arrangement
    //  3. If not, remove the movement from possible movements 

    //Creating a copy of movements list to avoid iterator invalidation 
    //while loooping in the list and removing elements
    std::list<Position> movements_copy = movements;

    for(Position movement : movements_copy)
    {
        BoardPositions new_arrangement = this->getNewArrangementFromMovement(movement, targetPiece);

        Position king_position = (targetPiece->getType() == PieceType::KING) ? movement : this->players->getCurrentPlayer()->getKingPosition();

        if(isCheckArrangement(new_arrangement, king_position))
            movements.remove(movement);

        if(movements.empty())
            break;
    }
}

BoardPositions Board::getNewArrangementFromMovement(Position targetPosition, const Piece* targetPiece) const 
{
    //  1. Get the current board positions
    //  2. Remove the targetPiece piece position from the new current player positions
    //  3. Add the new position of the targetPiece piece to the current player positions
    //  4. Get the opponent positions
    //  5. If the targetPosition is an attack, remove the opponent player positions
    //  6. Return the new arragement

    BoardPositions board_positions = this->getBoardPositions();

    std::list<Position> current_player_new_positions = board_positions.getCurrentPlayerPositions();
    current_player_new_positions.remove(targetPiece->getPosition());
    current_player_new_positions.push_back(targetPosition);

    std::list<Position> opponent_player_new_positions= board_positions.getOpponentPlayerPositions();
    bool is_attack = Position::find(opponent_player_new_positions, targetPosition);

    if(is_attack)
        opponent_player_new_positions.remove(targetPosition); 
    
    return BoardPositions(current_player_new_positions, opponent_player_new_positions);
}

bool Board::isCheckArrangement(const BoardPositions arrangement, Position kingPosition) const 
{
    //  1. For each opponent position of the new arrangement:
    //  2. Get the corresponding piece (if it not found, return false)
    //  3. Get the possible movements for the piece
    //  4. Check if the king position is in the possible movements
    //  5. If so, return false
    //  6. If all positions is already checked, return true

    for(Position position : arrangement.getOpponentPlayerPositions())
    {
        const Piece * opponent_piece = Piece::find(this->players->getOpponentPlayer()->getPieces(), position); 

        //Here we need to invert the board positions because the opponent will be the current player in the oppononet piece context 
        std::list<Position> possible_movements = opponent_piece->getPossibleMovements(BoardPositions(arrangement.getOpponentPlayerPositions(), arrangement.getCurrentPlayerPositions()));
        bool is_check = Position::find(possible_movements, kingPosition); 
        
        if(is_check)
            return true;
    }

    return false;
}

bool Board::isCheckmate()
{
    //  1. For each current player piece:
    //  2. Get the possible movements
    //  3. Remove unsafe movements
    //  4. If all movements were removed, return false
    //  5. If all pieces is already checked, return true

    std::list<Position> possible_movements;

    for(const Piece * piece : this->players->getCurrentPlayer()->getPieces())
    {
        possible_movements = this->getPossibleMovements(piece);

        if(possible_movements.size() > 0)
            return false;
    }

    return true;
}
