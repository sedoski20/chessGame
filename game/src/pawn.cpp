#include "pawn.h"
#include <algorithm>

Pawn::Pawn(Position initialPosition) : Piece(initialPosition)
{
	this->isFirstMovement = true;
	this->type = PieceType::PAWN;

	if(initialPosition.row == 1)
		this->direction = MovementDirection::MOVING_UP;
	else
		this->direction = MovementDirection::MOVING_DOWN;
}

std::list<Position> Pawn::getPossibleMovements(const BoardPositions &board) const
{
	std::list<Position> possible_movements;
	possible_movements.merge(getPawnMovements(board));
	possible_movements.merge(getPawnAtacks(board));

	return possible_movements;
}

 std::list<Position> Pawn::getPawnMovements(const BoardPositions &board) const
{
	Position possibleMovement(position.row, position.column);
	std::list<Position> movements;
	int direction_factor = getDirectionFactor();

	//1 step ahead
	possibleMovement.row = position.row + (1 * direction_factor);
	possibleMovement.column = position.column;

	if (possibleMovement.isValidPosition())
		if(!Position::find(board.getCurrentPlayerPositions(), possibleMovement))
			if(!Position::find(board.getOpponentPlayerPositions(), possibleMovement))
				movements.push_back(possibleMovement);

	//2 steps ahead
	if (this->isFirstMovement)
	{
		possibleMovement.row = position.row + (2 * direction_factor);
		possibleMovement.column = position.column;

		if (possibleMovement.isValidPosition())
			if (!Position::find(board.getCurrentPlayerPositions(), possibleMovement))
				if (!Position::find(board.getOpponentPlayerPositions(), possibleMovement))
					movements.push_back(possibleMovement);
	}

	return movements;
}

 std::list<Position> Pawn::getPawnAtacks(const BoardPositions &board) const
 {
	 Position possibleMovement(position.row, position.column);
	 std::list<Position> movements;
	 int direction_factor = getDirectionFactor();

	 //First diagonal
	 possibleMovement.row = position.row + (1 * direction_factor);
	 possibleMovement.column = position.column - 1;
	 if (possibleMovement.isValidPosition())
		 if(Position::find(board.getOpponentPlayerPositions(), possibleMovement))
			movements.push_back(possibleMovement);

	 //Second diagonal
	 possibleMovement.row = position.row + (1 * direction_factor);
	 possibleMovement.column = position.column + 1;
	 if (possibleMovement.isValidPosition())
		 if (Position::find(board.getOpponentPlayerPositions(), possibleMovement))
			 movements.push_back(possibleMovement);

	 return movements;
 }

 int Pawn::getDirectionFactor() const
 {
	//The direction of the Pawn is defined by the player side on the board. 
	 //If the player starts with the pieces on the botton side (row = 0) the paws move up (sum 1 or 2 from row).
	 //However, if the player starts on the top side, the paws move down (subtract 1 or 2 from row).
	 int direction_factor;
	 (this->direction == MovementDirection::MOVING_UP) ? direction_factor = 1 : direction_factor = -1;
	 
	 return direction_factor;
 }

 bool Pawn::move(Position position)
 {
    if (!position.isValidPosition())
        return false;

    if(this->isFirstMovement)
        this->isFirstMovement = false;

    this->position = position;
    return true;
 }
