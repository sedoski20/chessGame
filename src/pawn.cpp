#include "pawn.h"
#include <algorithm>

Pawn::Pawn(Position initialPosition) : Piece(initialPosition)
{
	this->isFirstMovement = true;

	if(initialPosition.row == 1)
		this->direction = MovementDirection::MOVING_UP;
	else
		this->direction = MovementDirection::MOVING_DOWN;
}

std::vector<Position> Pawn::getPossibleMovements(const std::vector<Position> & selfPieces, const std::vector<Position> & opponentPieces)
{
	std::vector<Position> possible_movements;
	getPawnMovements(possible_movements, selfPieces, opponentPieces);
	getPawnAtacks(possible_movements, opponentPieces);

	return possible_movements;
}

 void Pawn::getPawnMovements(std::vector<Position> & movements, const std::vector<Position> & selfPieces, const std::vector<Position> & opponentPieces)
{
	Position possibleMovement(currentPosition.row, currentPosition.column);
	int direction_factor = getDirectionFactor();

	//1 step ahead
	possibleMovement.row = currentPosition.row + (1 * direction_factor);
	possibleMovement.column = currentPosition.column;

	if (possibleMovement.isValidPosition())
		if(!isSomePieceOnPosition(possibleMovement, selfPieces))
			if(!isSomePieceOnPosition(possibleMovement, opponentPieces))
				movements.push_back(possibleMovement);

	//2 steps ahead
	if (this->isFirstMovement)
	{
		possibleMovement.row = currentPosition.row + (2 * direction_factor);
		possibleMovement.column = currentPosition.column;

		if (possibleMovement.isValidPosition())
			if (!isSomePieceOnPosition(possibleMovement, selfPieces))
				if (!isSomePieceOnPosition(possibleMovement, opponentPieces))
					movements.push_back(possibleMovement);
	}
}

 void Pawn::getPawnAtacks(std::vector<Position> & movements, const std::vector<Position> & opponentPieces)
 {
	 Position possibleMovement(currentPosition.row, currentPosition.column);
	 int direction_factor = getDirectionFactor();

	 //First diagonal
	 possibleMovement.row = currentPosition.row + (1 * direction_factor);
	 possibleMovement.column = currentPosition.column - 1;
	 if (possibleMovement.isValidPosition())
		 if(isSomePieceOnPosition(possibleMovement, opponentPieces))
			movements.push_back(possibleMovement);

	 //Second diagonal
	 possibleMovement.row = currentPosition.row + (1 * direction_factor);
	 possibleMovement.column = currentPosition.column + 1;
	 if (possibleMovement.isValidPosition())
		 if (isSomePieceOnPosition(possibleMovement, opponentPieces))
			 movements.push_back(possibleMovement);
 }

 bool Pawn::isSomePieceOnPosition(Position position, std::vector<Position> pieces)
 {
	 std::vector<Position>::iterator it = std::find(pieces.begin(), pieces.end(), position);

	 if (it != pieces.end())
		 return true;
	 else
		 return false;
 }

 int Pawn::getDirectionFactor() 
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

	this->currentPosition = position;
	return true;
}
