#ifndef PIECE_H
#define PIECE_H

#include "pieceinfo.h"
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
		template<class T>
		static T* find(const std::list<T*> pieces, Position positon)
		{
			for(T* p : pieces)
			{
				bool same_position = (p->getCurrentPosition() == positon);
				
				if(same_position)
					return p;
			}

			return NULL;
		}


protected: 
	Position currentPosition;
	PieceType type;

public: 
	Piece(Position initialPostion);
    virtual bool move(Position position);
	PieceType getType() const { return type; }
	Position getCurrentPosition() const;
	virtual std::list<Position> getPossibleMovements(const BoardPositions &board) const = 0;
};

#endif //PIECE_H
