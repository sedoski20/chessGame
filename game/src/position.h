#ifndef POSITION_H
#define POSITION_H

#include <string>
#include <list>

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
	bool operator==(const Position &other) const;
	bool operator<(const Position &other) const;
	static bool find(const std::list<Position>& positions, const Position position);
};

#endif // POSITION_H
