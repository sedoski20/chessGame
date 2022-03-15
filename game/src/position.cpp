#include "position.h"

Position::Position()
{
	this->row = 0;
	this->column = 0;
}

Position::Position(int row, int column)
{
	this->row = row;
	this->column = column;
}

bool Position::isValidPosition()
{
	if(this->row > 7 || this->row < 0)
		return false;

	if (this->column > 7 || this->column < 0)
		return false;

	return true;
}

std::string Position::toString()
{
	std::string position= char(this->column + 65) + std::to_string(this->row);
	return position;
}

bool Position::operator==(const Position& other) const
{
	if(this->row != other.row)
		return false;

	if (this->column != other.column)
		return false;

	return true;
}

bool Position::operator<(const Position& other) const
{
	if(this->row > other.row)
		return false;

	if (this->column > other.column)
		return false;

	return true;
}
