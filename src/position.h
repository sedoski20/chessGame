#ifndef POSITION_H
#define POSITION_H

#include <string>

class Position 
{
public:
	int row;
	int column;

public:
	Position();
	Position( int row,  int column);
	bool isValidPosition();
	std::string toString();
	bool operator==(const Position &other);
};


#endif // POSITION_H
