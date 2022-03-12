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

std::list<Position> Pawn::getPossibleMovements(BoardPositions &board) const
{
	std::list<Position> possible_movements;
	getPawnMovements(possible_movements, board.getCurrentPlayerPositions(), board.getOpponentPlayerPositions());
	getPawnAtacks(possible_movements, board.getOpponentPlayerPositions());

	return possible_movements;
}

 void Pawn::getPawnMovements(std::list<Position> & movements, const std::list<Position> & selfPositions, const std::list<Position> & opponentPositions) const
{
	Position possibleMovement(currentPosition.row, currentPosition.column);
	int direction_factor = getDirectionFactor();

	//1 step ahead
	possibleMovement.row = currentPosition.row + (1 * direction_factor);
	possibleMovement.column = currentPosition.column;

	if (possibleMovement.isValidPosition())
		if(!isSomePieceOnPosition(possibleMovement, selfPositions))
			if(!isSomePieceOnPosition(possibleMovement, opponentPositions))
				movements.push_back(possibleMovement);

	//2 steps ahead
	if (this->isFirstMovement)
	{
		possibleMovement.row = currentPosition.row + (2 * direction_factor);
		possibleMovement.column = currentPosition.column;

		if (possibleMovement.isValidPosition())
			if (!isSomePieceOnPosition(possibleMovement, selfPositions))
				if (!isSomePieceOnPosition(possibleMovement, opponentPositions))
					movements.push_back(possibleMovement);
	}
}

 void Pawn::getPawnAtacks(std::list<Position> & movements, const std::list<Position> & opponentPositions) const
 {
	 Position possibleMovement(currentPosition.row, currentPosition.column);
	 int direction_factor = getDirectionFactor();

	 //First diagonal
	 possibleMovement.row = currentPosition.row + (1 * direction_factor);
	 possibleMovement.column = currentPosition.column - 1;
	 if (possibleMovement.isValidPosition())
		 if(isSomePieceOnPosition(possibleMovement, opponentPositions))
			movements.push_back(possibleMovement);

	 //Second diagonal
	 possibleMovement.row = currentPosition.row + (1 * direction_factor);
	 possibleMovement.column = currentPosition.column + 1;
	 if (possibleMovement.isValidPosition())
		 if (isSomePieceOnPosition(possibleMovement, opponentPositions))
			 movements.push_back(possibleMovement);
 }

 bool Pawn::isSomePieceOnPosition(Position position, std::list<Position> pieces) const
 {
	 std::list<Position>::iterator it = std::find(pieces.begin(), pieces.end(), position);

	 if (it != pieces.end())
		 return true;
	 else
		 return false;
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
