#ifndef POSITION_H
#define POSITION_H

#include <string>
#include <list>

class Position 
{
public: //TODO: make private
	int x;
	int y;
	int row;
	int column;
	bool operator==(const Position &other) const;
	bool operator<(const Position &other) const;

public:
	Position(); //TODO: remove the default constructor
	Position( int row,  int column);
	bool isValidPosition();
	std::string toString();
	static bool find(const std::list<Position>& positions, const Position position);
};

#endif // POSITION_H
