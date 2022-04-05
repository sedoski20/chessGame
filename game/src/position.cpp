#include "position.h"
#include <algorithm>


Position::Position()
{
	this->row = 0;
	this->column = 0;
}

Position::Position(int row, int column)
{
	// TODO: add assert here to check if the position is valid
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

bool Position::find(const std::list<Position>& positions, const Position position) 
{
	// Here, we have to use "auto" because the result of std::find for a const std::list<Position> list
	//is a std::list<Position>::const_iterator and it is not convertible to std::list<Position>::iterator
	auto  iterator = std::find(positions.begin(), positions.end(), position);
	bool found_m1 = (iterator != std::end(positions));

	return found_m1;
}
