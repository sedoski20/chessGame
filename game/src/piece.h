#ifndef PIECE_H
#define PIECE_H

#include "piecetype.h"
#include "boardpositions.h"
#include <string>
#include <list>

enum class MovementDirection
{
	MOVING_UP,
	MOVING_DOWN
};

class Piece
{
	public:	
		//TODO: remove this method from here, it should be in a separated source file
		template<class T>
		static T* find(const std::list<T*> pieces, Position positon)
		{
			for(T* p : pieces)
			{
				bool same_position = (p->getPosition() == positon);
				
				if(same_position)
					return p;
			}

			return NULL;
		}


private: 
	Position position;
	PieceType type;

public: 
	Piece(Position initialPostion, PieceType type);
	virtual ~Piece();
    virtual bool move(Position position);
	PieceType getType() const { return type; }
	Position getPosition() const;
	virtual std::list<Position> getPossibleMovements(const BoardPositions &board) const = 0;
};

#endif //PIECE_H
